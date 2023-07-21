
#include <nusys.h>
#include <string.h>
#include <math.h>

#include "config.h"
#include "helper.h"
#include "sausage64.h"
#include "palette.h"
#include "tuk.h"
#include "palm_tree.h"
#include "cliff_1.h"
#include "cliff_2.h"
#include "cliff_3.h"
#include "cliff_4.h"
#include "cliff_5.h"
#include "ground_block.h"
#include "rock.h"
#include "beach_chair.h"
#include "math_util.h"
#include "time.h"
#include "entity.h"
#include "camera.h"
#include "controls.h"
#include "debug.h"


#define USB_BUFFER_SIZE 256


void change_mode();

void init_entity(Entity *entity);

void animcallback(u16 anim);

void set_light(LightData *light);
void set_viewport(Camera *camera, Entity entity);

void render_entity(Entity *entity);
void render_static_object(StaticObject *static_object);
void render_world(Entity entity, Camera *camera, LightData *light);

void render_debug_data();


TimeData time_data;

LightData light_data = {

    angle: { 0, 0, -70},
    ambcol: 40,
};

Camera cam = {

    distance_from_target: 800,
    angle_around_target: 0,
    pitch: 10, 
};

Entity tuk = {

    position: { 0, -200, 10},
    yaw: 75,
    type: TUK,
    scale: 1.0f
};


#define ANIM_SCENERY_COUNT 4
Entity animated_scenery[ANIM_SCENERY_COUNT] = {
    { scale: 1.f, position: { 18, 200, 0}, yaw: 1, type: PALM_TREE, framerate: 0.2},
    { scale: 1.3f, position: { 26, 194, 0}, yaw: 113, type: PALM_TREE, framerate: 0.45},
    { scale: 1.9f, position: { 24, 208, 0}, yaw: 267, type: PALM_TREE, framerate: 0.5},
    { scale: 1.9f, position: { 54, 238, 0}, yaw: 267, type: PALM_TREE, framerate: 0.6},
};

Mtx tukMtx[MESHCOUNT_tuk];
Mtx palm_treeMtx[MESHCOUNT_palm_tree];

/*
StaticObject cube = {
    
    position: { 0, 0, -20},
    mesh: gfx_beach,
    scale: 1.0f
};
*/

#define SCENERY_COUNT 5
StaticObject scenery[SCENERY_COUNT] = {
    { position: {  -3000,  2000,    0},     mesh: gfx_cliff_1,     scale: 1.0,}, 
    { position: {  -1500,  2000,    0},     mesh: gfx_cliff_2,     scale: 1.0 },
    { position: {      0,  2000,    0},     mesh: gfx_cliff_3,     scale: 1.0 },
    { position: {   1500,  2000,    0},     mesh: gfx_cliff_4,     scale: 1.0 },
    { position: {   3000,  2000,  200},     mesh: gfx_cliff_5,     scale: 1.0}
};


void init_entity(Entity *entity){

    if (entity->type == TUK) {
        sausage64_initmodel(&entity->model, MODEL_tuk, tukMtx);
        sausage64_set_anim(&entity->model, 0); 
        sausage64_set_animcallback(&entity->model, animcallback);
    }
    if (entity->type == PALM_TREE) {
        sausage64_initmodel(&entity->model, MODEL_palm_tree, palm_treeMtx);
        sausage64_set_anim(&entity->model, 0); 
        sausage64_set_animcallback(&entity->model, animcallback);
    }
}


void animcallback(u16 anim){
    entity_animcallback(&tuk);
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
    	camera->target[0], camera->target[1], camera->target[2],
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
    guScale(&entity->scale_mtx, entity->scale, entity->scale, entity->scale);

    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&entity->pos_mtx), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&entity->rot_mtx[0]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&entity->rot_mtx[1]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&entity->scale_mtx), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);

    sausage64_drawmodel(&glistp, &entity->model);

    gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
    gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
    gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
    gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
}


void render_static_object(StaticObject *static_object){
    
    guTranslate(&static_object->pos_mtx, static_object->position[0], static_object->position[1], static_object->position[2]);
    guRotate(&static_object->rot_mtx[0], static_object->pitch, 1, 0, 0);
    guRotate(&static_object->rot_mtx[1], static_object->yaw, 0, 0, 1);
    guScale(&static_object->scale_mtx, static_object->scale, static_object->scale, static_object->scale);

    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&static_object->pos_mtx), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&static_object->rot_mtx[0]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&static_object->rot_mtx[1]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&static_object->scale_mtx), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    
    gSPDisplayList(glistp++, static_object->mesh);

    gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
    gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
    gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
    gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
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

    render_entity(&tuk);

    for (int i = 0; i < SCENERY_COUNT; i++) {
        render_static_object(&scenery[i]);
    }
    
    /*
    // keep the skybox special for now, doesn't feel like it belongs with the other static objects in scenery
    render_static_object(&cube);

    for (int i = 0; i < ANIM_SCENERY_COUNT; i++) {
        render_entity(&animated_scenery[i]);
    }
    */
    
    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);
    
    osWritebackDCache(&camera->projection, sizeof(&camera->projection));
    osWritebackDCache(&camera->modeling, sizeof(camera->modeling));
}


void render_debug_data(){

    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 1);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "time %d", (int) get_time());
    
    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 2);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "FPS %d", (int) time_data.FPS);

    nuDebConTextPos(NU_DEB_CON_WINDOW0, 1, 3);
    nuDebConPrintf(NU_DEB_CON_WINDOW0, "framerate 0.%.d", (int)(tuk.framerate * 100));
}


void stage00_init(void){

    init_entity(&tuk);
    for (int i = 0; i < ANIM_SCENERY_COUNT; i++) {
        init_entity(&animated_scenery[i]);
    }
}


void stage00_update(void){
    
    debug_pollcommands();  
    
    time_management(&time_data);
    
    nuContDataGetEx(contdata, 0);
    
    move_entity(&tuk, cam, contdata, time_data);

    set_entity_state(&tuk);

    move_camera(&cam, tuk, contdata, time_data);

    sausage64_advance_anim(&tuk.model, tuk.framerate);

    for (int i = 0; i < ANIM_SCENERY_COUNT; i++) {
        sausage64_advance_anim(&animated_scenery[i].model, animated_scenery[i].framerate);
    }
}


void stage00_draw(void){
    

    glistp = glist;
    rcp_init();
    fb_clear(16, 32, 32);

    render_world(tuk, &cam, &light_data);    
    
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
