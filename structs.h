/*********************************
            Structs
*********************************/

#ifndef STRUCTS_H
#define STRUCTS_H


typedef struct{
    Light amb;
    Light dir;
	float angle[3];
	int ambcol;
}LightData;

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


#endif
