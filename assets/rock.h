// Generated by Arabiki64 V1.3
// By Buu342


// Custom combine mode to allow mixing primitive and vertex colors
#ifndef G_CC_PRIMLITE
    #define G_CC_PRIMLITE SHADE,0,PRIMITIVE,0,0,0,0,PRIMITIVE
#endif


/*********************************
              Models
*********************************/

static Vtx vtx_rock[] = {
    {6, -4, 11, 0, 0, 0, 61, -34, 106, 255}, /* 0 */
    {-7, -4, 11, 0, 0, 0, -57, -20, 112, 255}, /* 1 */
    {-1, -11, 6, 0, 0, 0, -6, -109, 64, 255}, /* 2 */
    {-12, -5, 6, 0, 0, 0, -91, -28, 85, 255}, /* 3 */
    {-4, 10, 6, 0, 0, 0, -24, 100, 75, 255}, /* 4 */
    {0, 9, 0, 0, 0, 0, 23, 124, 15, 255}, /* 5 */
    {8, 7, 6, 0, 0, 0, 74, 80, 65, 255}, /* 6 */
    {10, 8, 0, 0, 0, 0, 82, 86, 45, 255}, /* 7 */
    {10, -11, 0, 0, 0, 0, 75, -80, 63, 255}, /* 8 */
    {12, 0, 0, 0, 0, 0, 114, 2, 56, 255}, /* 9 */
    {2, 5, 11, 0, 0, 0, 18, 53, 114, 255}, /* 10 */
    {-10, 12, 0, 0, 0, 0, -53, 80, 84, 255}, /* 11 */
    {-16, 0, 0, 0, 0, 0, -93, 15, 85, 255}, /* 12 */
    {-11, -11, 0, 0, 0, 0, -64, -89, 65, 255}, /* 13 */
};

static Gfx gfx_rock[] = {
    gsSPVertex(vtx_rock+0, 14, 0),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_PRIMLITE, G_CC_PRIMLITE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPSetGeometryMode(G_SHADE | G_ZBUFFER | G_CULL_BACK | G_SHADING_SMOOTH | G_LIGHTING),
    gsDPSetPrimColor(0, 0, 100, 100, 100, 255),
    gsDPPipeSync(),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(3, 1, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(0, 8, 9, 0, 4, 10, 6, 0),
    gsSP2Triangles(11, 4, 5, 0, 10, 4, 1, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 6, 9, 0),
    gsSP2Triangles(6, 10, 0, 0, 3, 11, 12, 0),
    gsSP2Triangles(3, 12, 13, 0, 13, 2, 3, 0),
    gsSP2Triangles(8, 2, 13, 0, 0, 9, 6, 0),
    gsSP2Triangles(0, 2, 8, 0, 3, 4, 11, 0),
    gsSP1Triangle(10, 1, 0, 0),
    gsSPEndDisplayList(),
};
