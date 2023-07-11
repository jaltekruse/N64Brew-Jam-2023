#ifndef CAMERA_H
#define CAMERA_H


typedef struct {
	
	Mtx modeling;
	Mtx projection;
	Mtx viewpoint;
	Mtx camRot;
	u16 normal;

	float distance_from_player;
	float horizontal_distance_from_player;
	float vertical_distance_from_player;
    float angle_around_player;

	float pos[3];
	float pitch;
	float yaw;
	float roll;
} Camera;


typedef struct{
    Light amb;
    Light dir;
	float angle[3];
	int ambcol;
}LightData;


void set_camera_position(Camera *camera, Entity entity);


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

    if ((camera->vertical_distance_from_player + entity.pos[2]) < 5){camera->pos[2] = 5;}
}


#endif
