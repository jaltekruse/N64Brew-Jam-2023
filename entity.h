#ifndef ENTITY_H
#define ENTITY_H


typedef enum { 

	STAND,
	CROUCH,
    WALK,
	RUN,
        JOG,
        SPRINT,
    ATTACK,
        PUNCH,
        HOOK,
	ROLL,
	JUMP,
        FALL,
        LAND

} EntityState;


typedef enum {

	TUK,
    PALM_TREE

} EntityType;


typedef struct {

	Mtx	pos_mtx;
	Mtx	rot_mtx[3];
	Mtx scale_mtx;

    float scale;
	float position[3];
	float pitch;

	float target_yaw;
	float yaw;

	float force[3];
	float acceleration[3];

	float target_speed[3];
	float speed[3];

	float width;
	float height;
} Entity;

typedef struct {
    Entity entity;
	Gfx *mesh;

} StaticObject;

typedef struct {
    Entity entity;

	EntityType type;
	EntityState state;
	EntityState new_state;

    EntityState new_sub_state;
	EntityState sub_state;

	s64ModelHelper model;
    float framerate;

} AnimatedEntity;


void set_entity_position(Entity *entity, TimeData time_data);
void set_animation(AnimatedEntity *entity);
void entity_animcallback(AnimatedEntity *entity);
void set_entity_state(AnimatedEntity *entity);


void set_entity_position(Entity *entity, TimeData time_data){


    entity->position[0] += entity->speed[0] * time_data.frame_duration;
    entity->position[1] += entity->speed[1] * time_data.frame_duration;
    entity->position[2] += entity->speed[2] * time_data.frame_duration;

}
/*
#define ANIMATION_tuk_fall_idle_left   0
#define ANIMATION_tuk_fall_idle_right  1
#define ANIMATION_tuk_jump_left        2
#define ANIMATION_tuk_jump_right       3
#define ANIMATION_tuk_run_left         4
#define ANIMATION_tuk_run_right        5
#define ANIMATION_tuk_slide_left       6
#define ANIMATION_tuk_slide_right      7
#define ANIMATION_tuk_sprint_left      8
#define ANIMATION_tuk_sprint_right     9
#define ANIMATION_tuk_stand_idle_left  10
#define ANIMATION_tuk_stand_idle_right 11
#define ANIMATION_tuk_walk_left        12
#define ANIMATION_tuk_walk_right       13

*/

void set_animation(AnimatedEntity *entity) {

	if (entity->type == TUK) {

		if (entity->state  == STAND) {

            if (entity->entity.yaw > 0) sausage64_set_anim(&entity->model, 10);
            else if (entity->entity.yaw < 0) sausage64_set_anim(&entity->model, 11);
        }

		if (entity->state  == WALK) {

            if (entity->entity.yaw > 0) sausage64_set_anim(&entity->model, 12);
            else if (entity->entity.yaw < 0) sausage64_set_anim(&entity->model, 13);
        }

		if (entity->state  == RUN) {
            
            if (entity->sub_state == RUN){

                if (entity->entity.yaw > 0) sausage64_set_anim(&entity->model, 4);
                else if (entity->entity.yaw < 0) sausage64_set_anim(&entity->model, 5);
            }
            else
            if (entity->sub_state == SPRINT){

                if (entity->entity.yaw > 0) sausage64_set_anim(&entity->model, 8);
                else if (entity->entity.yaw < 0) sausage64_set_anim(&entity->model, 9);
            }
        }
		if (entity->state  == JUMP); {

            if (entity->entity.yaw > 0) sausage64_set_anim(&entity->model, 2);
            else if (entity->entity.yaw < 0) sausage64_set_anim(&entity->model, 3);
        }
/*
*/



	    //if (entity->state  == CROUCH);
		//if (entity->state  == ROLL);

    }
}


void entity_animcallback(AnimatedEntity *entity){

    switch(entity->state){

		case STAND: break;

		case CROUCH: break;

		case WALK: break;

		case RUN: break;

		case ATTACK: break;

        case ROLL: break;

        case JUMP: break;
    }
}


void set_entity_state(AnimatedEntity *entity) {
    
    if (entity->state == entity->new_state /*&& entity->sub_state == entity->new_sub_state*/) {
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
        entity->sub_state = entity->new_sub_state;
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
