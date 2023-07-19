
#include <nusys.h>
#include <string.h>
#include <math.h>

#include "config.h"
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


#define USB_BUFFER_SIZE 256
#define COS_45 0.7071
#define GRAVITY 980
#define NICKMASS 40


void change_mode();

void init_nick(Entity *entity);

void animcallback(u16 anim);

void set_light(LightData *light);
void set_viewport(Camera *camera, Entity entity);

void render_entity(Entity *entity);
void render_static_object(StaticObject *static_object);
void render_world(Entity entity, Camera *camera, LightData *light);

void render_debug_data();


TimeData time_data;

int mode = 1;

float anim_speed;

Camera cam = {

    distance_from_player: 200,
    pitch: 30,
    angle_around_player: 0,
};

LightData light_data = {

    angle: { 0, 0, -70},
    ambcol: 40,
};

Entity nick = {

    position: { 0, 0, 0},
    type: NICK,
};

Mtx nickMtx[MESHCOUNT_nick];

StaticObject cube = {
    
    pos: { 400, 300, 0},
    mesh: gfx_cube,
};


void init_nick(Entity *entity){

    if (entity->type == NICK) {
        sausage64_initmodel(&entity->model, MODEL_nick, nickMtx);
        sausage64_set_anim(&entity->model, ANIMATION_nick_look_around_left); 
        sausage64_set_animcallback(&entity->model, animcallback);
    }
}


void animcallback(u16 anim){
    entity_animcallback(&nick);
}


void set_light(LightData *light){

    int i;

    for (i=0; i<3; i++){
        light->amb.l.col[i] = light->ambcol;
        light->amb.l.colc[i] = light->ambcol;
        light->dir.l.col[i] = 255;
        light->dir.l.colc[i] = 255;
    }

    light->dir.l.dir[0] = -127*sinf(light->angle[0]*0.0174532925);
    light->dir.l.dir[1] = 127*sinf(light->angle[2]*0.0174532925)*cosf(light->angle[0]*0.0174532925);
    light->dir.l.dir[2] = 127*cosf(light->angle[2]*0.0174532925)*cosf(light->angle[0]*0.0174532925);

    gSPNumLights(glistp++, NUMLIGHTS_1);
    gSPLight(glistp++, &light->dir, 1);
    gSPLight(glistp++, &light->amb, 2);
    gDPPipeSync(glistp++);
}


void set_viewport(Camera *camera, Entity entity){

    guPerspective(
    	&camera->projection, &camera->normal, 
        45, (float)SCREEN_WD / (float)SCREEN_HT, 
    	10.0, 10000.0, 0.01);
    
    guLookAt(
    	&camera->viewpoint,
    	camera->position[0], camera->position[1], camera->position[2],
    	entity.position[0], entity.position[1], entity.position[2] + 100,
    	0, 0, 1
  	);

    gSPMatrix(glistp++, &camera->projection, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(glistp++, &camera->viewpoint, G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
    gSPPerspNormalize(glistp++, &camera->normal);

    guMtxIdent(&camera->modeling);
    gSPMatrix(glistp++, &camera->modeling, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
}


void render_entity(Entity *entity){

    guTranslate(&entity->pos_mtx, entity->position[0], entity->position[1], entity->position[2]);
    guRotate(&entity->rot_mtx[0], entity->pitch, 1, 0, 0);
    guRotate(&entity->rot_mtx[1], entity->yaw, 0, 0, 1);

    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&entity->pos_mtx), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&entity->rot_mtx[0]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&entity->rot_mtx[1]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);

    sausage64_drawmodel(&glistp, &entity->model);
}


void render_static_object(StaticObject *static_object){

    guTranslate(&static_object->pos_mtx, static_object->pos[0], static_object->pos[1], static_object->pos[2]);
    guRotate(&static_object->rot_mtx[0], 0, 1, 0, 0);
    guRotate(&static_object->rot_mtx[1], 0, 0, 0, 1);

    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&static_object->pos_mtx), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&static_object->rot_mtx[0]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&static_object->rot_mtx[1]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    
    gSPDisplayList(glistp++, static_object->mesh);
}


void render_world(Entity highlighted, Camera *camera, LightData *light){

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

    set_viewport(camera, highlighted);

    set_light(light);

    render_static_object(&cube);

    render_entity(&nick);
    
    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);
    
    osWritebackDCache(&camera->projection, sizeof(&camera->projection));
    osWritebackDCache(&camera->modeling, sizeof(camera->modeling));
}


void render_debug_data(){

    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 1);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "%d", (int)(nick.model.curkeyframe));
    
    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 2);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "%d", (int)(nick.model.curanimlen));

}


void stage00_init(void){

    init_nick(&nick);

    #if TV_TYPE == PAL    
        anim_speed = 0.66;
    #else-
        anim_speed = 0.5;
    #endif
}


void stage00_update(void){
    
    debug_pollcommands();  
    
    time_management(&time_data);
    
    nuContDataGetEx(contdata, 0);
    
    move_player(&nick, cam, contdata, time_data);

    set_entity_state(&nick);

    move_camera(&cam, nick, contdata, time_data);

    sausage64_advance_anim(&nick.model, anim_speed);
}


void stage00_draw(void){
    

    glistp = glist;
    rcp_init();
    fb_clear(16, 32, 32);

    render_world(nick, &cam, &light_data);    
    
    debug_assert((glistp-glist) < GLIST_LENGTH);
    #if TV_TYPE != PAL
        nuGfxTaskStart(glist, (s32)(glistp - glist) * sizeof(Gfx), NU_GFX_UCODE_F3DEX, NU_SC_NOSWAPBUFFER);
    #else
        nuGfxTaskStart(glist, (s32)(glistp - glist) * sizeof(Gfx), NU_GFX_UCODE_F3DEX, NU_SC_SWAPBUFFER);
    #endif
    
    #if TV_TYPE != PAL
        nuDebConClear(NU_DEB_CON_WINDOW0);
        render_debug_data();
        nuDebConDisp(NU_SC_SWAPBUFFER);
    #endif
}
