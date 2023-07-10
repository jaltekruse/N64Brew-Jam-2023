/***************************************************************
                           stage00.c
***************************************************************/

#include <nusys.h>
#include <string.h> // Needed for CrashSDK compatibility
#include <math.h>
#include "config.h"
#include "structs.h"
#include "helper.h"
#include "sausage64.h"
#include "palette.h"
#include "nick.h"
#include "cube.h"
#include "math_util.h"
#include "time.h"
#include "entity.h"
#include "camera.h"
#include "controls.h"
#include "debug.h"


/*********************************
              Macros
*********************************/

#define USB_BUFFER_SIZE 256
#define COS_45 0.7071
#define GRAVITY 980
#define NICKMASS 40

/*********************************
        Function Prototypes
*********************************/

void change_mode();

void init_nick(Entity *entity);

void animcallback(u16 anim);

void set_light(LightData *light);
void set_viewport(Camera *camera, Entity entity);

void render_entity(Entity *entity);
void render_static_object(StaticObject *static_object);
void render_world(Entity entity, Camera *camera, LightData *light);

void render_debug_data();

/*********************************
             Globals
*********************************/

//Variables

TimeData time_data;

int mode = 1;

float anim_speed;

// Camera
Camera cam = {

    distance_from_player: 1200,
    pitch: 30,
    angle_around_player: 0,
};

LightData light_data = {

    angle: { 0, 0, -70},
    ambcol: 40,
};


// Entities

Entity nick = {

    pos: { 0, 0, 0},
    type: NICK,
};

Mtx nickMtx[MESHCOUNT_nick];


StaticObject cube = {
    
    pos: { 400, 300, 0},
    mesh: gfx_cube,
};


// USB
static char uselight = TRUE;
static char renderaxis = TRUE;
static char freezelight = FALSE;
static char usb_buffer[USB_BUFFER_SIZE];




/*==============================================================
    change_mode
    changes gameplay style for the demo rom
==============================================================*/

void change_mode(){
    if (contdata->trigger & START_BUTTON && mode == 0){ mode = 1; }
    else if (contdata->trigger & START_BUTTON && mode == 1){ mode = 0;}
};



/*==============================================================
    init_nick
    sets up a sausage64 entity
==============================================================*/

void init_nick(Entity *entity){

    if (entity->type == NICK) {
        initmodel(&entity->model, MODEL_nick, nickMtx);
        set_anim(&entity->model, ANIMATION_nick_idle); 
        set_animcallback(&entity->model, animcallback);
    }
}


/*==============================================================
    animcallback
    Called before an animation finishes
==============================================================*/

void animcallback(u16 anim){
    
    // yes this currently ignores the passed in animation, might not be bad to verify we are finishing
    // the animation we are expecting, but this way the logic for where we go when transitioning out of
    // a given state can be shared across different animated entities, that can do some subset, of move/roll/runNING/etc.
    
    //entity_animcallback(&nick);
    entity_animcallback(&nick);
}



/*==============================================================
    set_light
    Sets the lights 
==============================================================*/

void set_light(LightData *light){

    int i;
    
    // Setup the lights
    if (!uselight)
        light->ambcol = 255;
    for (i=0; i<3; i++){
        light->amb.l.col[i] = light->ambcol;
        light->amb.l.colc[i] = light->ambcol;
        light->dir.l.col[i] = 255;
        light->dir.l.colc[i] = 255;
    }
    // handle the light direction so it's always projecting from the camera's position
    if (!freezelight){
        light->dir.l.dir[0] = -127*sinf(light->angle[0]*0.0174532925);
        light->dir.l.dir[1] = 127*sinf(light->angle[2]*0.0174532925)*cosf(light->angle[0]*0.0174532925);
        light->dir.l.dir[2] = 127*cosf(light->angle[2]*0.0174532925)*cosf(light->angle[0]*0.0174532925);
    }
    // Send the light struct to the RSP
    gSPNumLights(glistp++, NUMLIGHTS_1);
    gSPLight(glistp++, &light->dir, 1);
    gSPLight(glistp++, &light->amb, 2);
    gDPPipeSync(glistp++);
}


/*==============================================================
    set_viewport
    Sets the viewport
==============================================================*/

void set_viewport(Camera *camera, Entity entity){

    // Setup the cam.projection matrix
    guPerspective(
    	&camera->projection, &camera->normal, 
        45, (float)SCREEN_WD / (float)SCREEN_HT, 
    	10.0, 10000.0, 0.01);
    
    guLookAt(
    	&camera->viewpoint,
    	camera->pos[0], camera->pos[1], camera->pos[2],
    	entity.pos[0], entity.pos[1], entity.pos[2] + 100,
    	0, 0, 1
  	);

    // Apply the cam.projection matrix
    gSPMatrix(glistp++, &camera->projection, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(glistp++, &camera->viewpoint, G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
    gSPPerspNormalize(glistp++, &camera->normal);

    // Initialize the model matrix
    guMtxIdent(&camera->modeling);
    gSPMatrix(glistp++, &camera->modeling, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
}


/*==============================================================
    render_entity
    renders animated entities
==============================================================*/

void render_entity(Entity *entity){

    guTranslate(&entity->pos_mtx, entity->pos[0], entity->pos[1], entity->pos[2]);
    guRotate(&entity->rot_mtx[0], entity->pitch, 1, 0, 0);
    guRotate(&entity->rot_mtx[1], entity->yaw, 0, 0, 1);

    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&entity->pos_mtx), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&entity->rot_mtx[0]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&entity->rot_mtx[1]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);

    drawmodel(&glistp, &entity->model);
}


/*==============================================================
    render_static_object
    renders static objects
==============================================================*/

void render_static_object(StaticObject *static_object){

    guTranslate(&static_object->pos_mtx, static_object->pos[0], static_object->pos[1], static_object->pos[2]);
    guRotate(&static_object->rot_mtx[0], 0, 1, 0, 0);
    guRotate(&static_object->rot_mtx[1], 0, 0, 0, 1);

    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&static_object->pos_mtx), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&static_object->rot_mtx[0]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&static_object->rot_mtx[1]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    
    gSPDisplayList(glistp++, static_object->mesh);
}


/*==============================================================
    render_world
    calls the rendering functions
==============================================================*/

void render_world(Entity highlighted, Camera *camera, LightData *light){

    // Initialize the RCP to render stuff nicely
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
    gDPSetDepthSource(glistp++, G_ZS_PIXEL);
    gSPClearGeometryMode(glistp++,0xFFFFFFFF);
    gSPSetGeometryMode(glistp++, G_SHADE | G_ZBUFFER | G_CULL_BACK | G_SHADING_SMOOTH | G_LIGHTING);
    gSPTexture(glistp++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetRenderMode(glistp++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF);
    gDPSetCombineMode(glistp++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetTexturePersp(glistp++, G_TP_PERSP);
    gDPSetTextureFilter(glistp++, G_TF_BILERP);
    gDPSetTextureConvert(glistp++, G_TC_FILT);
    gDPSetTextureLOD(glistp++, G_TL_TILE);
    gDPSetTextureDetail(glistp++, G_TD_CLAMP);
    gDPSetTextureLUT(glistp++, G_TT_NONE);

    //set view matrix and lights
    set_viewport(camera, highlighted);

    set_light(light);

    //render the entities
    render_static_object(&cube);

    render_entity(&nick);
    
    // Syncronize the RCP and CPU and specify that our display list has ended
    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);

    // Ensure the cache lines are valid
    osWritebackDCache(&camera->projection, sizeof(&camera->projection));
    osWritebackDCache(&camera->modeling, sizeof(camera->modeling));
}


/*==============================================================
    render_debug_data
    renders debug data
==============================================================*/

void render_debug_data(){

    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 1);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "%d", (int)(nick.model.curkeyframe));
    
    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 2);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "%d", (int)(nick.model.curanimlen));

}


/*==============================================================
    stage00_init
    Initialize the stage
==============================================================*/

void stage00_init(void){

    // Initialize entities
    init_nick(&nick);
    
    // Set animation speed based on region
    #if TV_TYPE == PAL    
        anim_speed = 0.66;
    #else
        anim_speed = 0.5;
    #endif
}


/*==============================================================
    stage00_update
    Update stage variables every frame
==============================================================*/

void stage00_update(void){
    
    // Poll for USB commands
    debug_pollcommands();  

    //sets a clock
    time_management(&time_data);

    // Read the controller
    nuContDataGetEx(contdata, 0);

    //checks for mode change
    change_mode();

    //handle entity movement
    move_player(&nick, cam, contdata, time_data);

    move_camera(&cam, nick, contdata, time_data);
   
    // Advance animations
    advance_anim(&nick.model, anim_speed);
}


/*==============================================================
    stage00_draw
    render the stage
==============================================================================================*/

void stage00_draw(void){
    
    // Assign our glist pointer to our glist array for ease of access
    glistp = glist;

    // Initialize the RCP and framebuffer
    rcp_init();
    fb_clear(16, 32, 32);

    render_world(nick, &cam, &light_data);    

    // Ensure we haven't gone over the display list size and start the graphics task
    debug_assert((glistp-glist) < GLIST_LENGTH);
    #if TV_TYPE != PAL
        nuGfxTaskStart(glist, (s32)(glistp - glist) * sizeof(Gfx), NU_GFX_UCODE_F3DEX, NU_SC_NOSWAPBUFFER);
    #else
        nuGfxTaskStart(glist, (s32)(glistp - glist) * sizeof(Gfx), NU_GFX_UCODE_F3DEX, NU_SC_SWAPBUFFER);
    #endif
    
    // render the menu (doesn't work on PAL)
    #if TV_TYPE != PAL
        nuDebConClear(NU_DEB_CON_WINDOW0);
        render_debug_data();
        nuDebConDisp(NU_SC_SWAPBUFFER);
    #endif
}
