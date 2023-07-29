#ifndef ENTITY_H
#define ENTITY_H


typedef enum { 

	STAND,
	CROUCH,
    WALK,
	RUN,
    ATTACK,
	ROLL,
	JUMP,
	FALL

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


void set_animation(AnimatedEntity *entity) {

	if (entity->type == TUK) {

		if (entity->state  == STAND) {

            if (entity->entity.yaw > 0) sausage64_set_anim(&entity->model, 0);
            else if (entity->entity.yaw < 0) sausage64_set_anim(&entity->model, 1);
        }

	    //if (entity->state  == CROUCH);

		if (entity->state  == WALK) {

            if (entity->entity.yaw > 0) sausage64_set_anim(&entity->model, 2);
            else if (entity->entity.yaw < 0) sausage64_set_anim(&entity->model, 3);
        }

		if (entity->state  == RUN) {

            if (entity->entity.yaw > 0) sausage64_set_anim(&entity->model, 4);
            else if (entity->entity.yaw < 0) sausage64_set_anim(&entity->model, 5);
        }


		//if (entity->state  == ROLL);
		//if (entity->state  == JUMP);

    }
}


void entity_animcallback(AnimatedEntity *entity){

    switch(entity->state){

		case STAND: break;

		case CROUCH: break;

		case WALK: break;

		case RUN: break;

		case ATTACK: break;

        case ROLL: set_entity_state(entity); break;

        case JUMP: set_entity_state(entity); break;
    }
}


void set_entity_state(AnimatedEntity *entity) {
    
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
