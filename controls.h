#ifndef CONTROLS_H
#define CONTROLS_H


void acceleration_to_speed(Entity *entity, TimeData time);

void handle_player_platformer(Entity *entity, Camera camera, NUContData cont[1], TimeData time_data);
void handle_player_3d_shooter(Entity *entity, Camera camera, NUContData cont[1]);
void move_player(Entity *entity, Camera camera, NUContData cont[1], TimeData time_data);

void handle_camera_analog_stick(Camera *camera, NUContData cont[1], TimeData time_data);
void handle_camera_c_buttons(Camera *camera, NUContData cont[1], TimeData time_data);
void move_camera(Camera *camera, Entity entity, NUContData cont[1], TimeData time_data);


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

void handle_player_platformer(Entity *player, Camera camera, NUContData cont[1], TimeData time_data){
	
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
    if (player->pos[2] > 0 && player->speed[2] <= 0) {player->acceleration[2] = 2.5  * -10;} //gravity is higher when nick is falling
    else if (player->pos[2] > 0) {player->acceleration[2] = -10;}

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

void move_player(Entity *entity, Camera camera, NUContData cont[1], TimeData time_data){


        handle_player_platformer(entity, camera, cont, time_data);
        set_entity_position(entity, time_data);

}


/*==============================================================
    handle_camera_analog_stick
    moves camera with analog stick
==============================================================*/

void handle_camera_analog_stick(Camera *camera, NUContData cont[1], TimeData time_data){

    if (fabs(cont->stick_x) < 7) cont->stick_x = 0;
    if (fabs(cont->stick_y) < 7) cont->stick_y = 0;

    camera->angle_around_player += cont->stick_x * time_data.frame_duration;
    camera->pitch += cont->stick_y * time_data.frame_duration;

    if (camera->angle_around_player > 360) {camera->angle_around_player  = camera->angle_around_player - 360;}
    if (camera->angle_around_player < 0) {camera->angle_around_player  = camera->angle_around_player + 360;}

    if (camera->pitch > 85) camera->pitch = 85;
    if (camera->pitch < -85) camera->pitch = -85;
}


/*==============================================================
    handle_camera_c_buttons
    handles pitch, distance_from_player 
    and angle_around_player variables
==============================================================*/

void handle_camera_c_buttons(Camera *camera, NUContData cont[1], TimeData time_data){

    float zoom_input = lim(cont[0].button & D_CBUTTONS) - lim(contdata[0].button & U_CBUTTONS);
    float pan_input = lim(cont[0].button & R_CBUTTONS) - lim(contdata[0].button & L_CBUTTONS);

	if (zoom_input != 0) camera->pitch -= zoom_input * time_data.frame_duration * 70; 
    if (pan_input != 0) camera->angle_around_player += pan_input * time_data.frame_duration* 100;

    if (camera->distance_from_player > 2000) camera->distance_from_player = 2000; 
    if (camera->distance_from_player < 500) camera->distance_from_player = 500;

    if (camera->angle_around_player > 360) {camera->angle_around_player  = camera->angle_around_player - 360;}
    if (camera->angle_around_player < 0) {camera->angle_around_player  = camera->angle_around_player + 360;}

    if (camera->pitch > 85) camera->pitch = 85;
    if (camera->pitch < -85) camera->pitch = -85;
}


/*==============================================================
    move_camera
    Controls camera movement
==============================================================*/

void move_camera(Camera *camera, Entity entity, NUContData cont[1], TimeData time_data){

        handle_camera_c_buttons(camera, cont, time_data);
        set_camera_position(camera, entity);

}


#endif