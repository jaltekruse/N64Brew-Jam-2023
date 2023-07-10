#ifndef ENTITY_H
#define ENTITY_H



typedef enum { 
    IDLE,
    START_WALKING,
    WALKING, 
   	START_RUNNING, 
   	RUNNING,
	STOP_RUNNING,
	ROLL,
   	JUMP,
	AIRIDLE,	
	LAND
} EntityState;

typedef enum {
	NICK
} EntityType;

typedef struct {

	Mtx	pos_mtx;
	Mtx	rot_mtx[3];
	Mtx scale_mtx;

	float pos[3];
	float dir[3];
	float scale;

	float pitch;
	
	float target_yaw;
	float yaw;

	float force[3];
	float acceleration[3];

	float target_speed[3];
	float speed[3];

	float horizontal_speed;
	float vertical_speed;

	EntityType type;
	EntityState state;

	ModelHelper model;

	float input_amount;

} Entity;


void set_entity_position(Entity *entity, TimeData time_data);
void set_animation(Entity *entity);
void entity_animcallback(Entity *entity);
void set_entity_state(Entity *entity, EntityState new_state);


/*==============================================================
    set_entity_position
    calculates entity coordinates
==============================================================*/

void set_entity_position(Entity *entity, TimeData time_data){


    entity->pos[0] += entity->speed[0] * time_data.frame_duration;
    entity->pos[1] += entity->speed[1] * time_data.frame_duration;
    entity->pos[2] += entity->speed[2] * time_data.frame_duration;

}



/*==============================================================
    set_animation
    sets animation based on state
==============================================================*/

void set_animation(Entity *entity) {

        if (entity->type == NICK) {

        if (entity->state  == IDLE) set_anim(&entity->model, ANIMATION_nick_idle);
        if (entity->state  == START_WALKING) set_anim(&entity->model, ANIMATION_nick_start_walking);


        if (entity->state  == WALKING) set_anim_transition(&entity->model, ANIMATION_nick_walking);


        if (entity->state  == START_RUNNING) set_anim(&entity->model, ANIMATION_nick_start_running);


        if (entity->state  == RUNNING) set_anim_transition(&entity->model, ANIMATION_nick_running);


        if (entity->state  == STOP_RUNNING) set_anim(&entity->model, ANIMATION_nick_stop_running);
        if (entity->state  == ROLL) set_anim(&entity->model, ANIMATION_nick_sprinting_roll);
        if (entity->state  == JUMP) set_anim(&entity->model, ANIMATION_nick_jump);
        if (entity->state  == AIRIDLE) set_anim(&entity->model, ANIMATION_nick_falling_idle);
        if (entity->state  == LAND) set_anim(&entity->model, ANIMATION_nick_falling_to_landing);

    }
}


/*==============================================================
    entity_animcallback
    auxiliary function for generic subset of movements
==============================================================*/

void entity_animcallback(Entity *entity){

    // Go to idle animation when we finished attacking
    switch(entity->state)
    {
        case ROLL:
            set_entity_state(entity, IDLE);
            break;

        case JUMP:
            set_entity_state(entity, AIRIDLE);
            break;

        case LAND:
            set_entity_state(entity, IDLE);
            break;

         case START_WALKING:
            set_entity_state(entity, WALKING);
            break;

         case START_RUNNING:
            set_entity_state(entity, RUNNING);
            break;
    }
}


/*==============================================================
    set_entity_state
    sets entity state and changes animation
==============================================================*/


void set_entity_state(Entity *entity, EntityState new_state) {
    
    if (entity->state == new_state){
        return;
    }

    if (new_state == IDLE && 
            (    entity->state == START_WALKING 
              || entity->state == WALKING 
              || entity->state == START_RUNNING 
              || entity->state == RUNNING 
              || entity->state == ROLL 
              || entity->state == JUMP
              || entity->state == AIRIDLE 
              || entity->state == LAND)){

        entity->state = new_state;
        set_animation(entity);
    }

    if (new_state == START_WALKING && 
            (    entity->state == IDLE)){

        entity->state = new_state;
        set_animation(entity);
    }

    if (new_state == WALKING && 
            (    entity->state == IDLE
              || entity->state == START_WALKING
              || entity->state == RUNNING)){

        entity->state = new_state;
        set_animation(entity);
    }

    if (new_state == START_RUNNING && 
            (    entity->state == IDLE
              || entity->state == START_WALKING)){

        entity->state = new_state;
        set_animation(entity);
    }

    if (new_state == RUNNING && 
            (    entity->state == IDLE 
              || entity->state == START_RUNNING
              || entity->state == WALKING)){

        entity->state = new_state;
        set_animation(entity);
    }

    if (entity->state == STOP_RUNNING &&
                entity->state == RUNNING){

        entity->state = new_state;
        set_animation(entity);
    }

    if (new_state == ROLL && 
            (    entity->state == IDLE 
              || entity->state == WALKING 
              || entity->state == RUNNING)){

        entity->state = new_state;
        set_animation(entity);
    }

    if (new_state == JUMP && 
            (    entity->state == IDLE
              || entity->state == START_WALKING
              || entity->state == WALKING 
              || entity->state == START_RUNNING
              || entity->state == RUNNING)){

        entity->state = new_state;
        set_animation(entity);
    }

    if (new_state == AIRIDLE){

        entity->state = new_state;
        set_animation(entity);
    }

    if (new_state == LAND){

        entity->state = new_state;
        set_animation(entity);
    }
}


#endif
