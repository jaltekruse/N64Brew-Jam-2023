#ifndef CONTROLS_H
#define CONTROLS_H

#define GRAVITY 1000

void entity_acceleration_to_speed(Entity *entity, TimeData time);
void move_entity_stick_2d(AnimatedEntity *entity, Camera camera, NUContData cont[1], TimeData time_data);
void move_entity_stick_3d(AnimatedEntity *entity, Camera camera, NUContData cont[1], TimeData time_data);
void move_entity(AnimatedEntity *entity, Camera camera, NUContData cont[1], TimeData time_data);

void move_camera_stick(Camera *camera, NUContData cont[1], TimeData time_data);
void move_camera_c_buttons(Camera *camera, NUContData cont[1], TimeData time_data);
void move_camera(Camera *camera, Entity entity, NUContData cont[1], TimeData time_data);


void entity_acceleration_to_speed(Entity *entity, TimeData time){

    entity->speed[0] += (entity->acceleration[0] * time.frame_duration);
    entity->speed[1] += (entity->acceleration[1] * time.frame_duration);
    entity->speed[2] += (entity->acceleration[2] * time.frame_duration);
}


void move_entity_stick_2d(AnimatedEntity *animated_entity, Camera camera, NUContData cont[1], TimeData time_data){

    Entity* entity = &animated_entity->entity;
    float input_amount = cont->stick_x;
    
	if (fabs(input_amount) < 7){input_amount = 0;} 

    if (input_amount == 0){

        if  (fabs(entity->speed[0]) < 1){
            
            entity->speed[0] = 0;
            
            animated_entity->framerate = 0.5f;
            animated_entity->new_state = STAND;
        }else{

            entity->target_speed[0] = 0;
            entity->acceleration[0] = 15 * (entity->target_speed[0] - entity->speed[0]);
        }
    }
    else
    if (fabs(input_amount) > 0){

        entity->target_speed[0] = input_amount * 8;
        entity->acceleration[0] = 10 * (entity->target_speed[0] - entity->speed[0]);

        if (fabs(entity->speed[0]) < 300) {
            
            animated_entity->framerate = fabs(entity->speed[0]) / 450;
            animated_entity->new_state = WALK;
        }
        else {

            animated_entity->framerate = fabs(entity->speed[0]) / 1000;
            animated_entity->new_state = RUN;
        }
    }

    if (animated_entity->state == JUMP) {

        entity->acceleration[0] = entity->acceleration[0] / 20;
        return;
    }
    
    
    //set yaw and direction
    if (entity->speed[0] > 0 && input_amount > 0) entity->yaw = 75;
    if (entity->speed[0] < 0 && input_amount < 0) entity->yaw = -75;
}

void handle_entity_actions(AnimatedEntity *animated_entity, Camera camera, NUContData cont[1], TimeData time_data){
    
    Entity* entity = &animated_entity->entity;
    // set jump
    if (cont[0].trigger & A_BUTTON 
            && entity->position[2] == 0 
            && animated_entity->state != ROLL){
          
        entity->target_speed[2] = 300;
        entity->acceleration[2] = 100 * (entity->target_speed[2] - entity->speed[2]);

        animated_entity->new_state = JUMP;
    }

    // apply gravity (it's higher when nick is falling)
    if (entity->position[2] > 0 && entity->speed[2] <= 0) entity->acceleration[2] = 2.5  * -GRAVITY;
    else if (entity->position[2] > 0) entity->acceleration[2] = -GRAVITY;

    // set ground collision
    if (entity->position[2] < 0) {
        
        entity->acceleration[2] = 0;
        entity->speed[2] = 0;
        entity->position[2] = 0;

        animated_entity->new_state = STAND; 
    }
}

void move_entity_stick_3d(AnimatedEntity *animated_entity, Camera camera, NUContData cont[1], TimeData time_data){
    
    Entity* entity = &animated_entity->entity;
	if (fabs(cont->stick_x) < 7){cont->stick_x = 0;}
	if (fabs(cont->stick_y) < 7){cont->stick_y = 0;}

    float input_amount = 1 / qi_sqrt(cont->stick_x * cont->stick_x +  cont->stick_y *  cont->stick_y);
    
    entity->target_yaw = atan2(cont->stick_x, -cont->stick_y) - rad(camera.angle_around_target);
    
    if (input_amount = 0){
        
        if  (fabs(entity->speed[0]) < 1 && fabs(entity->speed[1]) < 1){
            entity->speed[0] = 0;
            entity->speed[1] = 0;
            
            animated_entity->new_state = STAND;
        }

        entity->acceleration[0] = 9 * (0 - entity->speed[0]);
        entity->acceleration[1] = 9 * (0 - entity->speed[1]);
    }
    else
    if (input_amount > 0 && input_amount <= 60){

        entity->target_speed[0] = 200 * sin(entity->target_yaw);
        entity->target_speed[1] = 200 * -cos(entity->target_yaw);

        entity->acceleration[0] = 4 * (entity->target_speed[0] - entity->speed[0]);
        entity->acceleration[1] = 4 * (entity->target_speed[1] - entity->speed[1]);

        animated_entity->new_state = WALK;
    }else
    if (input_amount > 60){

        entity->target_speed[0] = 600 * sin(entity->target_yaw);
        entity->target_speed[1] = 600 * -cos(entity->target_yaw);

        entity->acceleration[0] = 4 * (entity->target_speed[0] - entity->speed[0]);
        entity->acceleration[1] = 4 * (entity->target_speed[1] - entity->speed[1]);

        animated_entity->new_state = RUN;
    }
    
    if (entity->speed[0] != 0 || entity->speed[1] != 0) entity->yaw = deg(atan2(entity->speed[0], -entity->speed[1]));
}

void move_entity(AnimatedEntity *animated_entity, Camera camera, NUContData cont[1], TimeData time_data){

        move_entity_stick_2d(animated_entity, camera, cont, time_data);
        handle_entity_actions(animated_entity, camera, cont, time_data);
        entity_acceleration_to_speed(&animated_entity->entity, time_data);
        set_entity_position(&animated_entity->entity, time_data);
}


void move_camera_stick(Camera *camera, NUContData cont[1], TimeData time_data){

    if (fabs(cont->stick_x) < 7) cont->stick_x = 0;
    if (fabs(cont->stick_y) < 7) cont->stick_y = 0;

    camera->angle_around_target += cont->stick_x * time_data.frame_duration;
    camera->pitch += cont->stick_y * time_data.frame_duration;

    if (camera->angle_around_target > 360) {camera->angle_around_target  = camera->angle_around_target - 360;}
    if (camera->angle_around_target < 0) {camera->angle_around_target  = camera->angle_around_target + 360;}

    if (camera->pitch > 85) camera->pitch = 85;
    if (camera->pitch < -85) camera->pitch = -85;
}


void move_camera_c_buttons(Camera *camera, NUContData cont[1], TimeData time_data){

    float zoom_input = lim(cont[0].button & D_CBUTTONS) - lim(contdata[0].button & U_CBUTTONS);
    float pan_input = lim(cont[0].button & R_CBUTTONS) - lim(contdata[0].button & L_CBUTTONS);

	if (zoom_input != 0) camera->pitch -= zoom_input * time_data.frame_duration * 70; 
    if (pan_input != 0) camera->angle_around_target += pan_input * time_data.frame_duration* 100;

    if (camera->distance_from_target > 2000) camera->distance_from_target = 2000; 
    if (camera->distance_from_target < 500) camera->distance_from_target = 500;

    if (camera->angle_around_target > 360) {camera->angle_around_target  = camera->angle_around_target - 360;}
    if (camera->angle_around_target < 0) {camera->angle_around_target  = camera->angle_around_target + 360;}

    if (camera->pitch > 85) camera->pitch = 85;
    if (camera->pitch < -85) camera->pitch = -85;
}


void move_camera(Camera *camera, Entity entity, NUContData cont[1], TimeData time_data){

        //move_camera_c_buttons(camera, cont, time_data);
        set_camera_position_2d(camera, entity);

}


#endif