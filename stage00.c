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
#include "math_util.h"
#include "time.h"
#include "nick.h"
#include "entity.h"
#include "cube.h"
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


void handle_player_platformer(Entity *entity, Camera camera, NUContData cont[1]);
void handle_player_3d_shooter(Entity *entity, Camera camera, NUContData cont[1]);
void move_player(Entity *entity, Camera camera, NUContData cont[1]);

void handle_camera_analog_stick(Camera *camera, NUContData cont[1]);
void handle_camera_c_buttons(Camera *camera, NUContData cont[1]);
void set_camera_position(Camera *camera, Entity entity);
void move_camera(Camera *camera, Entity entity, NUContData cont[1]);

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
    acceleration_to_speed
    Calculates speed based on entity acceleration
==============================================================*/

void acceleration_to_speed(Entity *entity, TimeData time){

    entity->speed[0] += (entity->acceleration[0] * time.frame_duration);
    entity->speed[1] += (entity->acceleration[1] * time.frame_duration);
    entity->speed[2] += (entity->acceleration[2] * time.frame_duration);

}


/*==============================================================
    handle_player_platformer
    Moves the main character platformer style
==============================================================*/

void handle_player_platformer(Entity *player, Camera camera, NUContData cont[1]){
	
    // deadzone
	if (fabs(cont->stick_x) < 7){cont->stick_x = 0;}
	if (fabs(cont->stick_y) < 7){cont->stick_y = 0;}

    float input_amount = 1 / qi_sqrt(cont->stick_x * cont->stick_x +  cont->stick_y *  cont->stick_y);

    // set target yaw
    player->target_yaw = atan2(cont->stick_x, -cont->stick_y) - rad(camera.angle_around_player);    

    // set target speed
    if (cont->stick_x == 0 && cont->stick_y == 0
            && player->state != ROLL
            && player->state != JUMP
            && player->state != AIRIDLE
            && player->state != LAND){

        player->target_speed[0] = 0;
        player->target_speed[1] = 0;
        
        // set speed value to 0 when it is under 1
        if  (fabs(player->speed[0]) < 1 && fabs(player->speed[1]) < 1){

            player->speed[0] = 0;
            player->speed[1] = 0;
        }

    }else
    if ((cont->stick_x == 0 && cont->stick_y == 0 && (player->speed[0] / sin(rad(player->yaw)) > 600))){
            // set stop running set if no input and speed > 600
            set_entity_state(player, STOP_RUNNING);
        }

    else
    if (input_amount > 0 && input_amount <= 60
            && player->state != ROLL
            && player->state != JUMP
            && player->state != AIRIDLE
            && player->state != LAND){

        player->target_speed[0] = 200 * sin(player->target_yaw);
        player->target_speed[1] = 200 * -cos(player->target_yaw);

        if (player->state == IDLE ){

            set_entity_state(player, START_WALKING);
        }
        if (player->state == RUNNING){

            set_entity_state(player, WALKING);
        }
    }else
    if (input_amount > 60
            && player->state != ROLL
            && player->state != JUMP
            && player->state != AIRIDLE
            && player->state != LAND){

        player->target_speed[0] = 600 * sin(player->target_yaw);
        player->target_speed[1] = 600 * -cos(player->target_yaw);
                
        if (player->state == IDLE 
            || player->state == START_WALKING){

            set_entity_state(player, START_RUNNING);

        }
        if (player->state == WALKING ){

            set_entity_state(player, RUNNING);
        }
    }

    // set acceleration when stopping
    if (cont->stick_x == 0 && cont->stick_y == 0){
        
    player->acceleration[0] = 9 * (player->target_speed[0] - player->speed[0]);
    player->acceleration[1] = 9 * (player->target_speed[1] - player->speed[1]);

    }else
    // set acceleration when starting to move
    if (input_amount > 0){

    player->acceleration[0] = 4 * (player->target_speed[0] - player->speed[0]);
    player->acceleration[1] = 4 * (player->target_speed[1] - player->speed[1]);

    }
    
    // set jump
    if (cont[0].trigger & A_BUTTON 
            && player->pos[2] == 0 
            && player->state != ROLL){
        
        set_entity_state(player, JUMP);
            
        player->target_speed[2] = 500;

        player->acceleration[2] = 100 * (player->target_speed[2] - player->speed[2]);

    }

    // apply gravity
    if (player->pos[2] > 0 && player->speed[2] <= 0) {player->acceleration[2] = 2.5  * -GRAVITY;} //gravity is higher when nick is falling
    else if (player->pos[2] > 0) {player->acceleration[2] = -GRAVITY;}

    player->target_speed[2] = 0;

    if (player->pos[2] < 200 && player->speed[2] < 0) set_entity_state(player, LAND);
   
    if ( player->pos[2] == 0 && player->state == LAND){
        
    }

    // set speed
    acceleration_to_speed(player, time_data);


    if (player->pos[2] < 0) {
        
        player->acceleration[2] = 0;
        player->speed[2] = 0;
        player->pos[2] = 0;
    }

    // set yaw
    if (player->speed[0] != 0 || player->speed[1] != 0) player->yaw = deg(atan2(player->speed[0], -player->speed[1]));


    // set idle state 
    if (player->speed[0] == 0 
        && player->speed[1] == 0
        && player->pos[2] == 0
        && player->state != ROLL
        && player->state != JUMP 
        && player->state != AIRIDLE 
        && player->state != LAND){

        set_entity_state(player, IDLE);
    }
}





/*==============================================================
    handle_player_3d_shooter
    Moves the main character 3d shooter style
==============================================================*/

void handle_player_3d_shooter(Entity *player, Camera camera, NUContData cont[1]){

    float forward_input = lim(cont[0].button & D_CBUTTONS) - lim(contdata[0].button & U_CBUTTONS);
    float side_input = lim(cont[0].button & R_CBUTTONS) - lim(contdata[0].button & L_CBUTTONS);

    if (cont[0].trigger & Z_TRIG){
        
        set_entity_state(player, ROLL);
        
    }
    
    if (cont[0].trigger & R_TRIG){
        
        set_entity_state(player, JUMP);
        if (player->pos[2] == 0 && player->state != ROLL) player->vertical_speed = 700;

    }

    if (player->state != ROLL
            && player->state != JUMP
            && player->state != AIRIDLE
            && player->state != LAND){

        if (forward_input != 0 || side_input != 0) {
            player->yaw = deg(atan2(side_input, forward_input) - rad(camera.angle_around_player));
            player->horizontal_speed = 500;
        }
        
        if (forward_input == 0 && side_input == 0) {
            player->horizontal_speed = 0;
        }
    }

    if (player->horizontal_speed > 400) {
        set_entity_state(player, RUNNING);
    } else 
    if (player->horizontal_speed > 0) {
        set_entity_state(player, WALKING);
    }

    if (player->horizontal_speed == 0
        && player->pos[2] == 0
        && player->state != ROLL
        && player->state != JUMP 
        && player->state != AIRIDLE 
        && player->state != LAND){

        set_entity_state(player, IDLE);
    }
}



/*==============================================================
    move_player
    Controls entity movement
==============================================================*/

void move_player(Entity *entity, Camera camera, NUContData cont[1]){


        handle_player_platformer(entity, camera, cont);
        set_entity_position(entity, time_data);

}


/*==============================================================
    handle_camera_analog_stick
    moves camera with analog stick
==============================================================*/

void handle_camera_analog_stick(Camera *camera, NUContData cont[1]){

    if (fabs(cont->stick_x) < 7) cont->stick_x = 0;
    if (fabs(cont->stick_y) < 7) cont->stick_y = 0;

    camera->angle_around_player += cont->stick_x * time_data.frame_duration;
    camera->pitch += cont->stick_y * time_data.frame_duration;

    if (cam.angle_around_player > 360) {cam.angle_around_player  = cam.angle_around_player - 360;}
    if (cam.angle_around_player < 0) {cam.angle_around_player  = cam.angle_around_player + 360;}

    if (camera->pitch > 85) cam.pitch = 85;
    if (camera->pitch < -85) cam.pitch = -85;
}


/*==============================================================
    handle_camera_c_buttons
    handles pitch, distance_from_player 
    and angle_around_player variables
==============================================================*/

void handle_camera_c_buttons(Camera *camera, NUContData cont[1]){

    float zoom_input = lim(cont[0].button & D_CBUTTONS) - lim(contdata[0].button & U_CBUTTONS);
    float pan_input = lim(cont[0].button & R_CBUTTONS) - lim(contdata[0].button & L_CBUTTONS);

	if (zoom_input != 0) camera->distance_from_player += zoom_input * time_data.frame_duration * 1000; 
    if (pan_input != 0) camera->angle_around_player -= pan_input * time_data.frame_duration* 100;

    if (camera->distance_from_player > 2000) camera->distance_from_player = 2000; 
    if (camera->distance_from_player < 500) camera->distance_from_player = 500;

    if (cam.angle_around_player > 360) {cam.angle_around_player  = cam.angle_around_player - 360;}
    if (cam.angle_around_player < 0) {cam.angle_around_player  = cam.angle_around_player + 360;}
}


/*==============================================================
    set_camera_position
    calculates camera coordinates
==============================================================*/

void set_camera_position(Camera *camera, Entity entity){

    camera->horizontal_distance_from_player = camera->distance_from_player * cos(rad(camera->pitch));
	camera->vertical_distance_from_player = camera->distance_from_player * sin(rad(camera->pitch));

    camera->pos[0] = entity.pos[0] - camera->horizontal_distance_from_player * sin(rad(camera->angle_around_player));
    camera->pos[1] = entity.pos[1] - camera->horizontal_distance_from_player * cos(rad(camera->angle_around_player));
    camera->pos[2] = camera->vertical_distance_from_player + entity.pos[2];

    if ((camera->vertical_distance_from_player + entity.pos[2]) < 5){cam.pos[2] = 5;}
}


/*==============================================================
    move_camera
    Controls camera movement
==============================================================*/

void move_camera(Camera *camera, Entity entity, NUContData cont[1]){

        handle_camera_c_buttons(camera, cont);
        set_camera_position(camera, entity);

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





    /*
    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 3);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "target jump speed %d", (int)nick.target_speed[2]);

    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 4);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "jump acceleration %d", (int)nick.acceleration[2]);

    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 1);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "",);

    if (mode == 0){
        nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 1);
        nuDebConPrintf(NU_DEB_CON_WINDOW0, "start to change mode");

        nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 2);
        nuDebConPrintf(NU_DEB_CON_WINDOW0, "c buttons to move nick");
        
        nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 3);
        nuDebConPrintf(NU_DEB_CON_WINDOW0, "analog stick to pan camera");

        nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 4);
        nuDebConPrintf(NU_DEB_CON_WINDOW0, "r to jump");

        nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 5);
        nuDebConPrintf(NU_DEB_CON_WINDOW0, "z to roll");
    } else 
    if (mode == 1){

        nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 1);
         nuDebConPrintf(NU_DEB_CON_WINDOW0, "start to change mode");

        nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 2);
        nuDebConPrintf(NU_DEB_CON_WINDOW0, "analog stick to move nick");
        
        nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 3);
        nuDebConPrintf(NU_DEB_CON_WINDOW0, "c buttons to pan camera");

        nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 4);
        nuDebConPrintf(NU_DEB_CON_WINDOW0, "a to jump");

        nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 5);
        nuDebConPrintf(NU_DEB_CON_WINDOW0, "b to roll");
    }

    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 6);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "vertical distance %d", (int)cam.vertical_distance_from_player);
    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 7);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "cam x %d", (int)cam.pos[0]);
    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 8);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "cam y %d", (int)cam.pos[1]);
    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 9);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "cam z %d", (int)cam.pos[2]);
    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 10);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "time %d", (int)get_time());
    */
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
    move_player(&nick, cam, contdata);

    move_camera(&cam, nick, contdata);
   
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
