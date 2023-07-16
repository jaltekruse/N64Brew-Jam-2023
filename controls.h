#ifndef CONTROLS_H
#define CONTROLS_H


void acceleration_to_speed(Entity *entity, TimeData time);

void move_player_stick(Entity *entity, Camera camera, NUContData cont[1], TimeData time_data);
void move_player(Entity *entity, Camera camera, NUContData cont[1], TimeData time_data);

void move_camera_stick(Camera *camera, NUContData cont[1], TimeData time_data);
void move_camera_c_buttons(Camera *camera, NUContData cont[1], TimeData time_data);
void move_camera(Camera *camera, Entity entity, NUContData cont[1], TimeData time_data);


void acceleration_to_speed(Entity *entity, TimeData time){

    entity->speed[0] += (entity->acceleration[0] * time.frame_duration);
    entity->speed[1] += (entity->acceleration[1] * time.frame_duration);
    entity->speed[2] += (entity->acceleration[2] * time.frame_duration);
}


void move_player_stick(Entity *entity, Camera camera, NUContData cont[1], TimeData time_data){
    
	if (fabs(cont->stick_x) < 7){cont->stick_x = 0;}
	if (fabs(cont->stick_y) < 7){cont->stick_y = 0;}

    float input_amount = 1 / qi_sqrt(cont->stick_x * cont->stick_x +  cont->stick_y *  cont->stick_y);
    
    entity->target_yaw = atan2(cont->stick_x, -cont->stick_y) - rad(camera.angle_around_player);
    
    if (cont->stick_x == 0 && cont->stick_y == 0){
        
        if  (fabs(entity->speed[0]) < 1 && fabs(entity->speed[1]) < 1){
            entity->speed[0] = 0;
            entity->speed[1] = 0;
            entity-> new_state = STAND;
        }

        entity->target_speed[0] = 0;
        entity->target_speed[1] = 0;

        entity->acceleration[0] = 9 * (entity->target_speed[0] - entity->speed[0]);
        entity->acceleration[1] = 9 * (entity->target_speed[1] - entity->speed[1]);
    }
    else
    if (input_amount > 0 && input_amount <= 60){

        entity->target_speed[0] = 200 * sin(entity->target_yaw);
        entity->target_speed[1] = 200 * -cos(entity->target_yaw);

        entity->acceleration[0] = 4 * (entity->target_speed[0] - entity->speed[0]);
        entity->acceleration[1] = 4 * (entity->target_speed[1] - entity->speed[1]);
        entity-> new_state = WALK;
    }else
    if (input_amount > 60){

        entity->target_speed[0] = 600 * sin(entity->target_yaw);
        entity->target_speed[1] = 600 * -cos(entity->target_yaw);

        entity->acceleration[0] = 4 * (entity->target_speed[0] - entity->speed[0]);
        entity->acceleration[1] = 4 * (entity->target_speed[1] - entity->speed[1]);
        entity->new_state = RUN;
    }
    
    acceleration_to_speed(entity, time_data);
    
    if (entity->speed[0] != 0 || entity->speed[1] != 0) entity->yaw = deg(atan2(entity->speed[0], -entity->speed[1]));
}


void move_player(Entity *entity, Camera camera, NUContData cont[1], TimeData time_data){

        move_player_stick(entity, camera, cont, time_data);
        set_entity_position(entity, time_data);
}


void move_camera_stick(Camera *camera, NUContData cont[1], TimeData time_data){

    if (fabs(cont->stick_x) < 7) cont->stick_x = 0;
    if (fabs(cont->stick_y) < 7) cont->stick_y = 0;

    camera->angle_around_player += cont->stick_x * time_data.frame_duration;
    camera->pitch += cont->stick_y * time_data.frame_duration;

    if (camera->angle_around_player > 360) {camera->angle_around_player  = camera->angle_around_player - 360;}
    if (camera->angle_around_player < 0) {camera->angle_around_player  = camera->angle_around_player + 360;}

    if (camera->pitch > 85) camera->pitch = 85;
    if (camera->pitch < -85) camera->pitch = -85;
}


void move_camera_c_buttons(Camera *camera, NUContData cont[1], TimeData time_data){

    osSyncPrintf("begin move_camera_c_buttons\n");
    float zoom_input = lim(cont[0].button & D_CBUTTONS) - lim(contdata[0].button & U_CBUTTONS);
    osSyncPrintf("1 move_camera_c_buttons\n");
    float pan_input = lim(cont[0].button & R_CBUTTONS) - lim(contdata[0].button & L_CBUTTONS);\
    osSyncPrintf("2 move_camera_c_buttons\n");

	if (zoom_input != 0) camera->pitch -= zoom_input * time_data.frame_duration * 70; 
    osSyncPrintf("3 move_camera_c_buttons\n");
    if (pan_input != 0) camera->angle_around_player += pan_input * time_data.frame_duration* 100;
    osSyncPrintf("4 move_camera_c_buttons\n");

    if (camera->distance_from_player > 2000) camera->distance_from_player = 2000;
    osSyncPrintf("5 move_camera_c_buttons\n");
    if (camera->distance_from_player < 500) camera->distance_from_player = 500;
    osSyncPrintf("6 move_camera_c_buttons\n");

    if (camera->angle_around_player > 360) {camera->angle_around_player  = camera->angle_around_player - 360;}
    osSyncPrintf("7 move_camera_c_buttons\n");
    if (camera->angle_around_player < 0) {camera->angle_around_player  = camera->angle_around_player + 360;}
    osSyncPrintf("8 move_camera_c_buttons\n");

    if (camera->pitch > 85) camera->pitch = 85;
    osSyncPrintf("9 move_camera_c_buttons\n");
    if (camera->pitch < -85) camera->pitch = -85;
    osSyncPrintf("10 move_camera_c_buttons\n");
}


void move_camera(Camera *camera, Entity entity, NUContData cont[1], TimeData time_data){

        move_camera_c_buttons(camera, cont, time_data);
        osSyncPrintf("after move_camera_c_buttons\n");
        set_camera_position(camera, entity);
        osSyncPrintf("after set_camera_position\n");

}


#endif