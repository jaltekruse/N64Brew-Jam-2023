#ifndef ENTITY_H
#define ENTITY_H


typedef struct {

	Mtx	pos_mtx;
	Mtx	rot_mtx[3];
	Mtx scale_mtx;

	float pos[3];
	float dir[3];
	float pitch;
	float yaw;
	float scale;

	Gfx *mesh;

} StaticObject;


typedef enum { 

	STAND,
	CROUCH,
    WALK,
	RUN,
	ROLL,
	JUMP,
	FALL

} EntityState;


typedef enum {

	NICK

} EntityType;


typedef struct {

	Mtx	pos_mtx;
	Mtx	rot_mtx[3];
	Mtx scale_mtx;

	float position[3];
	float pitch;

	float target_yaw;
	float yaw;

	float force[3];
	float acceleration[3];

	float target_speed[3];
	float speed[3];
	
	EntityType type;
	EntityState state;
	EntityState new_state;

	s64ModelHelper model;

} Entity;


void set_entity_position(Entity *entity, TimeData time_data);
void set_animation(Entity *entity);
void entity_animcallback(Entity *entity);
void set_entity_state(Entity *entity);


/*==============================================================
    set_entity_position
    calculates entity coordinates
==============================================================*/

void set_entity_position(Entity *entity, TimeData time_data){


    entity->position[0] += entity->speed[0] * time_data.frame_duration;
    entity->position[1] += entity->speed[1] * time_data.frame_duration;
    entity->position[2] += entity->speed[2] * time_data.frame_duration;

}



/*==============================================================
    set_animation
    sets animation based on state
==============================================================*/

void set_animation(Entity *entity) {

	if (entity->type == NICK) {

		if (entity->state  == STAND) sausage64_set_anim(&entity->model, ANIMATION_nick_tap_shoe_left);
		if (entity->state  == CROUCH) sausage64_set_anim(&entity->model, ANIMATION_nick_tap_shoe_left);
		if (entity->state  == WALK) sausage64_set_anim(&entity->model, ANIMATION_nick_walk_left);
		if (entity->state  == RUN) sausage64_set_anim(&entity->model, ANIMATION_nick_run_left);
		if (entity->state  == ROLL) sausage64_set_anim(&entity->model, ANIMATION_nick_run_to_roll_left);
		if (entity->state  == JUMP) sausage64_set_anim(&entity->model, ANIMATION_nick_jump_left);

    }
}


/*==============================================================
    entity_animcallback
    auxiliary function for generic subset of movements
==============================================================*/

void entity_animcallback(Entity *entity){

    switch(entity->state){

		case STAND: break;

		case CROUCH: break;

		case WALK: break;

		case RUN: break;

        case ROLL: set_entity_state(entity); break;

        case JUMP: set_entity_state(entity); break;
    }
}


/*==============================================================
    set_entity_state
    sets entity state and changes animation
==============================================================*/


void set_entity_state(Entity *entity) {
    
    if (entity->state == entity->new_state){
        return;
    }

    if (entity->new_state == STAND && 
              (  entity->state == WALK
              || entity->state == RUN
              || entity->state == ROLL 
              || entity->state == JUMP)){

        entity->state = entity->new_state;
        set_animation(entity);
    }

	if (entity->new_state == CROUCH && 
				entity->state == STAND){

        entity->state = entity->new_state;
        set_animation(entity);
    }

    if (entity->new_state == WALK && 
              (  entity->state == STAND
              || entity->state == RUN)){

        entity->state = entity->new_state;
        set_animation(entity);
    }

    if (entity->new_state == RUN && 
              (  entity->state == STAND
              || entity->state == WALK)){

        entity->state = entity->new_state;
        set_animation(entity);
    }

    if (entity->new_state == ROLL && 
              (  entity->state == STAND 
              || entity->state == WALK 
              || entity->state == RUN)){

        entity->state = entity->new_state;
        set_animation(entity);
    }

    if (entity->new_state == JUMP && 
              (  entity->state == STAND
              || entity->state == WALK
              || entity->state == RUN)){

        entity->state = entity->new_state;
        set_animation(entity);
    }
}


#endif
