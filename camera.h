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

	float position[3];
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

    camera->position[0] = entity.position[0] - camera->horizontal_distance_from_player * sin(rad(camera->angle_around_player));
    camera->position[1] = entity.position[1] - camera->horizontal_distance_from_player * cos(rad(camera->angle_around_player));
    camera->position[2] = camera->vertical_distance_from_player + entity.position[2];

    if ((camera->vertical_distance_from_player + entity.position[2]) < 5){camera->position[2] = 5;}
}


#endif
