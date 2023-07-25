#ifndef CAMERA_H
#define CAMERA_H


typedef struct {
	
	Mtx modeling;
	Mtx projection;
	Mtx viewpoint;
	Mtx camRot;
	u16 normal;

	float distance_from_target;
	float horizontal_distance_from_target;
	float vertical_distance_from_target;
    float angle_around_target;

	float position[3];
	float target[3];
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
void set_camera_position_2d(Camera *camera, Entity entity);


void set_camera_position(Camera *camera, Entity entity){

    camera->horizontal_distance_from_target = camera->distance_from_target * cos(rad(camera->pitch));
	camera->vertical_distance_from_target = camera->distance_from_target * sin(rad(camera->pitch));

    camera->position[0] = entity.position[0] - camera->horizontal_distance_from_target * sin(rad(camera->angle_around_target));
    camera->position[1] = entity.position[1] - camera->horizontal_distance_from_target * cos(rad(camera->angle_around_target));
    camera->position[2] = camera->vertical_distance_from_target + entity.position[2];
	
	camera->target[0] = entity.position[0];
	camera->target[1] = entity.position[1];
	camera->target[2] = entity.position[2] + 250;

    if ((camera->vertical_distance_from_target + entity.position[2]) < 5){camera->position[2] = 5;}
}

void set_camera_position_2d(Camera *camera, Entity entity){

    camera->horizontal_distance_from_target = camera->distance_from_target * cos(rad(camera->pitch));
	camera->vertical_distance_from_target = camera->distance_from_target * sin(rad(camera->pitch));

	camera->position[0] = entity.position[0];	
    camera->position[1] = entity.position[1] - camera->horizontal_distance_from_target;
    camera->position[2] = camera->vertical_distance_from_target + entity.position[2] + 35;

	camera->target[0] = entity.position[0];
	camera->target[1] = entity.position[1];
	camera->target[2] = entity.position[2] + 170;

    if ((camera->vertical_distance_from_target + entity.position[2]) < 5){camera->position[2] = 5;}
}

#endif
