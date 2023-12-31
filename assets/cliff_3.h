// Generated by Arabiki64 V1.3
// By Buu342


// Custom combine mode to allow mixing primitive and vertex colors
#ifndef G_CC_PRIMLITE
    #define G_CC_PRIMLITE SHADE,0,PRIMITIVE,0,0,0,0,PRIMITIVE
#endif


/*********************************
              Models
*********************************/

static Vtx vtx_cliff_3[] = {
    {353, 289, -1, 0, 0, 0, -80, -54, 83, 255}, /* 0 */
    {439, 266, 4, 0, 0, 0, 40, -90, 81, 255}, /* 1 */
    {447, 364, -7, 0, 0, 0, 46, 47, 109, 255}, /* 2 */
    {496, 397, -75, 0, 0, 0, 100, 75, 20, 255}, /* 3 */
    {372, 415, -47, 0, 0, 0, -55, 106, 44, 255}, /* 4 */
    {476, 280, -138, 0, 0, 0, 94, -85, 14, 255}, /* 5 */
    {321, 290, -164, 0, 0, 0, -117, -46, 17, 255}, /* 6 */
    {339, 375, -169, 0, 0, 0, -93, 86, -9, 255}, /* 7 */
    {449, 386, -261, 0, 0, 0, 61, 93, -62, 255}, /* 8 */
    {369, 375, -293, 0, 0, 0, -51, 67, -96, 255}, /* 9 */
    {337, 194, -244, 0, 0, 0, -68, -103, -29, 255}, /* 10 */
    {502, 293, -252, 0, 0, 0, 115, -26, -47, 255}, /* 11 */
    {378, 231, -285, 0, 0, 0, -15, -73, -103, 255}, /* 12 */
    {-573, -119, -292, 0, 0, 0, -77, 15, -100, 255}, /* 13 */
    {-535, -571, -268, 0, 0, 0, -92, -48, -73, 255}, /* 14 */
    {-610, -56, -106, 0, 0, 0, -123, -25, -18, 255}, /* 15 */
    {-534, 59, -213, 0, 0, 0, -29, -22, -122, 255}, /* 16 */
    {-346, -57, -277, 0, 0, 0, -11, 9, -126, 255}, /* 17 */
    {-633, 107, -248, 0, 0, 0, -69, -39, -99, 255}, /* 18 */
    {-230, 219, -285, 0, 0, 0, 6, -6, -127, 255}, /* 19 */
    {-609, 177, -270, 0, 0, 0, -65, -12, -109, 255}, /* 20 */
    {-682, 139, -128, 0, 0, 0, -125, 0, -23, 255}, /* 21 */
    {-594, -51, 160, 0, 0, 0, -122, -32, 16, 255}, /* 22 */
    {-669, 277, 16, 0, 0, 0, -126, 7, 15, 255}, /* 23 */
    {-658, 204, 173, 0, 0, 0, -125, 15, 16, 255}, /* 24 */
    {-673, 456, -59, 0, 0, 0, -123, -30, -7, 255}, /* 25 */
    {-594, 279, 132, 0, 0, 0, -124, 23, 12, 255}, /* 26 */
    {-614, 509, -278, 0, 0, 0, -45, 28, -116, 255}, /* 27 */
    {-670, 546, 100, 0, 0, 0, -127, 9, 1, 255}, /* 28 */
    {-703, 535, -234, 0, 0, 0, -97, -29, -76, 255}, /* 29 */
    {-728, 581, -41, 0, 0, 0, -121, 35, 18, 255}, /* 30 */
    {-690, 604, -212, 0, 0, 0, -58, 93, -64, 255}, /* 31 */
    {-614, 649, 40, 0, 0, 0, -37, 121, -5, 255}, /* 32 */
    {-728, 581, -41, 0, 0, 0, -121, 35, 18, 255}, /* 33 */
    {-670, 546, 100, 0, 0, 0, -127, 9, 1, 255}, /* 34 */
    {-690, 604, -212, 0, 0, 0, -58, 93, -64, 255}, /* 35 */
    {-614, 509, -278, 0, 0, 0, -45, 28, -116, 255}, /* 36 */
    {-405, 596, -114, 0, 0, 0, 0, 121, -38, 255}, /* 37 */
    {-87, 525, -291, 0, 0, 0, 21, 48, -116, 255}, /* 38 */
    {-230, 219, -285, 0, 0, 0, 6, -6, -127, 255}, /* 39 */
    {-686, 650, 223, 0, 0, 0, -89, 89, 17, 255}, /* 40 */
    {-669, 339, 216, 0, 0, 0, -115, -54, 4, 255}, /* 41 */
    {-594, 279, 132, 0, 0, 0, -124, 23, 12, 255}, /* 42 */
    {-562, 624, 337, 0, 0, 0, -13, 104, 72, 255}, /* 43 */
    {-621, 293, 225, 0, 0, 0, -123, -21, 24, 255}, /* 44 */
    {-658, 204, 173, 0, 0, 0, -125, 15, 16, 255}, /* 45 */
    {-631, 542, 383, 0, 0, 0, -79, 34, 93, 255}, /* 46 */
    {-602, 388, 370, 0, 0, 0, -92, -43, 76, 255}, /* 47 */
    {-631, 219, 331, 0, 0, 0, -106, 36, 59, 255}, /* 48 */
    {-594, -51, 160, 0, 0, 0, -122, -32, 16, 255}, /* 49 */
    {-538, 288, 360, 0, 0, 0, -71, -3, 105, 255}, /* 50 */
    {-520, 434, 454, 0, 0, 0, -35, 2, 122, 255}, /* 51 */
    {-369, 547, 387, 0, 0, 0, -2, 69, 106, 255}, /* 52 */
    {-393, 645, 271, 0, 0, 0, 0, 123, 32, 255}, /* 53 */
    {-72, 379, 426, 0, 0, 0, 2, 9, 127, 255}, /* 54 */
    {-105, 606, 409, 0, 0, 0, 6, 77, 101, 255}, /* 55 */
    {-49, 624, -40, 0, 0, 0, 15, 126, 3, 255}, /* 56 */
    {-134, 218, 461, 0, 0, 0, 11, 2, 127, 255}, /* 57 */
    {-161, 657, -181, 0, 0, 0, -13, 118, -45, 255}, /* 58 */
    {31, 603, -166, 0, 0, 0, 81, 88, -43, 255}, /* 59 */
    {38, 611, 153, 0, 0, 0, 79, 99, -7, 255}, /* 60 */
    {-27, 650, 301, 0, 0, 0, 43, 117, 24, 255}, /* 61 */
    {64, 516, 76, 0, 0, 0, 116, 53, -3, 255}, /* 62 */
    {25, 525, 399, 0, 0, 0, 79, 68, 72, 255}, /* 63 */
    {-27, 650, 301, 0, 0, 0, 43, 117, 24, 255}, /* 64 */
    {77, 546, 280, 0, 0, 0, 124, 21, 20, 255}, /* 65 */
    {38, 611, 153, 0, 0, 0, 79, 99, -7, 255}, /* 66 */
    {25, 525, 399, 0, 0, 0, 79, 68, 72, 255}, /* 67 */
    {64, 516, 76, 0, 0, 0, 116, 53, -3, 255}, /* 68 */
    {-105, 606, 409, 0, 0, 0, 6, 77, 101, 255}, /* 69 */
    {32, 465, 440, 0, 0, 0, 49, 34, 112, 255}, /* 70 */
    {-72, 379, 426, 0, 0, 0, 2, 9, 127, 255}, /* 71 */
    {69, 495, -190, 0, 0, 0, 105, 49, -52, 255}, /* 72 */
    {31, 603, -166, 0, 0, 0, 81, 88, -43, 255}, /* 73 */
    {-87, 525, -291, 0, 0, 0, 21, 48, -116, 255}, /* 74 */
    {143, 410, 381, 0, 0, 0, 96, 58, 59, 255}, /* 75 */
    {30, 214, 413, 0, 0, 0, 69, -29, 103, 255}, /* 76 */
    {-134, 218, 461, 0, 0, 0, 11, 2, 127, 255}, /* 77 */
    {117, 313, -128, 0, 0, 0, 122, 33, 11, 255}, /* 78 */
    {153, 288, -241, 0, 0, 0, 104, -4, -73, 255}, /* 79 */
    {-230, 219, -285, 0, 0, 0, 6, -6, -127, 255}, /* 80 */
    {139, 170, -7, 0, 0, 0, 125, -22, -5, 255}, /* 81 */
    {182, 312, 405, 0, 0, 0, 98, -11, 80, 255}, /* 82 */
    {68, 98, -163, 0, 0, 0, 95, -12, -83, 255}, /* 83 */
    {94, 53, 151, 0, 0, 0, 123, 13, 29, 255}, /* 84 */
    {106, 81, -26, 0, 0, 0, 83, -93, -23, 255}, /* 85 */
    {-35, -43, 431, 0, 0, 0, 49, 11, 117, 255}, /* 86 */
    {244, -296, -70, 0, 0, 0, 118, 46, 3, 255}, /* 87 */
    {125, -101, 232, 0, 0, 0, 109, 55, 36, 255}, /* 88 */
    {-56, -197, -294, 0, 0, 0, 22, 12, -125, 255}, /* 89 */
    {-346, -57, -277, 0, 0, 0, -11, 9, -126, 255}, /* 90 */
    {-535, -571, -268, 0, 0, 0, -92, -48, -73, 255}, /* 91 */
    {127, -287, -249, 0, 0, 0, 60, 13, -111, 255}, /* 92 */
    {-169, -543, -309, 0, 0, 0, 6, -14, -126, 255}, /* 93 */
    {261, -350, -141, 0, 0, 0, 25, 67, -105, 255}, /* 94 */
    {-2, -627, -264, 0, 0, 0, 37, -68, -101, 255}, /* 95 */
    {-535, -571, -268, 0, 0, 0, -92, -48, -73, 255}, /* 96 */
    {-169, -543, -309, 0, 0, 0, 6, -14, -126, 255}, /* 97 */
    {-380, -711, -264, 0, 0, 0, -37, -98, -72, 255}, /* 98 */
    {-2, -627, -264, 0, 0, 0, 37, -68, -101, 255}, /* 99 */
    {127, -287, -249, 0, 0, 0, 60, 13, -111, 255}, /* 100 */
    {177, -586, -202, 0, 0, 0, 59, -72, -86, 255}, /* 101 */
    {261, -350, -141, 0, 0, 0, 25, 67, -105, 255}, /* 102 */
    {-59, -722, -104, 0, 0, 0, 25, -123, -21, 255}, /* 103 */
    {-355, -701, 196, 0, 0, 0, -44, -113, 37, 255}, /* 104 */
    {-456, -551, 324, 0, 0, 0, -103, -54, 51, 255}, /* 105 */
    {-594, -51, 160, 0, 0, 0, -122, -32, 16, 255}, /* 106 */
    {124, -684, 228, 0, 0, 0, 66, -99, 45, 255}, /* 107 */
    {-424, -588, 336, 0, 0, 0, -58, -80, 80, 255}, /* 108 */
    {86, -601, 327, 0, 0, 0, 46, -70, 95, 255}, /* 109 */
    {-400, -489, 385, 0, 0, 0, -9, -64, 110, 255}, /* 110 */
    {-44, -498, 378, 0, 0, 0, 5, -46, 118, 255}, /* 111 */
    {87, -504, 380, 0, 0, 0, 45, -42, 111, 255}, /* 112 */
    {137, -358, 394, 0, 0, 0, 78, -20, 98, 255}, /* 113 */
    {-292, -355, 456, 0, 0, 0, -10, -20, 125, 255}, /* 114 */
    {-464, -495, 360, 0, 0, 0, -97, -61, 55, 255}, /* 115 */
    {-458, -489, 385, 0, 0, 0, -65, -75, 80, 255}, /* 116 */
    {-524, -98, 387, 0, 0, 0, -79, -28, 96, 255}, /* 117 */
    {-627, 87, 382, 0, 0, 0, -111, -13, 60, 255}, /* 118 */
    {-631, 219, 331, 0, 0, 0, -106, 36, 59, 255}, /* 119 */
    {-538, 288, 360, 0, 0, 0, -71, -3, 105, 255}, /* 120 */
    {-545, 129, 441, 0, 0, 0, -45, 14, 118, 255}, /* 121 */
    {-134, 218, 461, 0, 0, 0, 11, 2, 127, 255}, /* 122 */
    {-35, -43, 431, 0, 0, 0, 49, 11, 117, 255}, /* 123 */
    {96, -163, 413, 0, 0, 0, 73, 39, 97, 255}, /* 124 */
    {125, -101, 232, 0, 0, 0, 109, 55, 36, 255}, /* 125 */
    {219, -279, 260, 0, 0, 0, 123, 15, 26, 255}, /* 126 */
    {151, -408, 299, 0, 0, 0, 117, -29, 41, 255}, /* 127 */
    {125, -101, 232, 0, 0, 0, 109, 55, 36, 255}, /* 128 */
    {219, -279, 260, 0, 0, 0, 123, 15, 26, 255}, /* 129 */
    {203, -291, 136, 0, 0, 0, 120, 40, 14, 255}, /* 130 */
    {244, -296, -70, 0, 0, 0, 118, 46, 3, 255}, /* 131 */
    {213, -394, 155, 0, 0, 0, 115, -2, 54, 255}, /* 132 */
    {151, -408, 299, 0, 0, 0, 117, -29, 41, 255}, /* 133 */
    {259, -345, -19, 0, 0, 0, 28, 122, 21, 255}, /* 134 */
    {261, -350, -141, 0, 0, 0, 25, 67, -105, 255}, /* 135 */
    {274, -363, 76, 0, 0, 0, -8, 81, 97, 255}, /* 136 */
    {233, -544, 116, 0, 0, 0, 71, -82, 65, 255}, /* 137 */
    {124, -684, 228, 0, 0, 0, 66, -99, 45, 255}, /* 138 */
    {302, -306, -22, 0, 0, 0, -113, 57, -5, 255}, /* 139 */
    {164, -554, -24, 0, 0, 0, 69, -105, 17, 255}, /* 140 */
    {177, -586, -202, 0, 0, 0, 59, -72, -86, 255}, /* 141 */
    {325, -495, 135, 0, 0, 0, 10, -36, 121, 255}, /* 142 */
    {368, -597, 19, 0, 0, 0, 38, -101, 67, 255}, /* 143 */
    {342, -624, -38, 0, 0, 0, -5, -127, 4, 255}, /* 144 */
    {325, -277, 120, 0, 0, 0, -101, 15, 75, 255}, /* 145 */
    {418, -504, 47, 0, 0, 0, 78, -81, 59, 255}, /* 146 */
    {424, -610, -79, 0, 0, 0, 74, -98, -32, 255}, /* 147 */
    {322, -527, -145, 0, 0, 0, 22, -58, -111, 255}, /* 148 */
    {448, -518, -131, 0, 0, 0, 77, -65, -77, 255}, /* 149 */
    {431, -405, 130, 0, 0, 0, -13, -74, 103, 255}, /* 150 */
    {268, -483, -142, 0, 0, 0, -2, -4, -127, 255}, /* 151 */
    {311, -458, -197, 0, 0, 0, -28, -35, -119, 255}, /* 152 */
    {429, -408, -168, 0, 0, 0, 21, -56, -112, 255}, /* 153 */
    {374, -281, -187, 0, 0, 0, -92, 13, -87, 255}, /* 154 */
    {542, -417, -100, 0, 0, 0, 94, -77, -37, 255}, /* 155 */
    {488, -301, -306, 0, 0, 0, -7, -49, -117, 255}, /* 156 */
    {514, -445, 82, 0, 0, 0, 71, -95, 46, 255}, /* 157 */
    {640, -262, -33, 0, 0, 0, 123, -31, 9, 255}, /* 158 */
    {469, -368, 203, 0, 0, 0, -11, -67, 107, 255}, /* 159 */
    {565, -261, 218, 0, 0, 0, 74, -26, 100, 255}, /* 160 */
    {469, -368, 203, 0, 0, 0, -11, -67, 107, 255}, /* 161 */
    {514, -445, 82, 0, 0, 0, 71, -95, 46, 255}, /* 162 */
    {640, -262, -33, 0, 0, 0, 123, -31, 9, 255}, /* 163 */
    {325, -277, 120, 0, 0, 0, -101, 15, 75, 255}, /* 164 */
    {452, -45, 220, 0, 0, 0, -34, 75, 97, 255}, /* 165 */
    {302, -248, -25, 0, 0, 0, -123, 27, -17, 255}, /* 166 */
    {302, -306, -22, 0, 0, 0, -113, 57, -5, 255}, /* 167 */
    {374, -281, -187, 0, 0, 0, -92, 13, -87, 255}, /* 168 */
    {566, -57, 205, 0, 0, 0, 74, 65, 80, 255}, /* 169 */
    {399, -23, 126, 0, 0, 0, -78, 93, 37, 255}, /* 170 */
    {569, 39, -99, 0, 0, 0, 44, 119, -10, 255}, /* 171 */
    {383, -164, -132, 0, 0, 0, -123, 26, 15, 255}, /* 172 */
    {431, 30, -126, 0, 0, 0, -64, 105, -33, 255}, /* 173 */
    {347, -132, -183, 0, 0, 0, -123, 20, -24, 255}, /* 174 */
    {491, -92, -273, 0, 0, 0, -23, 52, -113, 255}, /* 175 */
    {488, -301, -306, 0, 0, 0, -7, -49, -117, 255}, /* 176 */
    {633, -38, -176, 0, 0, 0, 91, 75, -47, 255}, /* 177 */
    {665, -34, -68, 0, 0, 0, 95, 48, 69, 255}, /* 178 */
    {639, -252, -242, 0, 0, 0, 95, -56, -63, 255}, /* 179 */
    {637, -60, -246, 0, 0, 0, 77, 69, -74, 255}, /* 180 */
};

static Gfx gfx_cliff_3[] = {
    gsSPVertex(vtx_cliff_3+0, 32, 0),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_PRIMLITE, G_CC_PRIMLITE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPSetGeometryMode(G_SHADE | G_ZBUFFER | G_CULL_BACK | G_SHADING_SMOOTH | G_LIGHTING),
    gsDPSetPrimColor(0, 0, 127, 127, 127, 255),
    gsDPPipeSync(),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(2, 4, 0, 0, 2, 3, 4, 0),
    gsSP2Triangles(0, 5, 1, 0, 5, 3, 1, 0),
    gsSP2Triangles(6, 0, 4, 0, 0, 6, 5, 0),
    gsSP2Triangles(7, 4, 3, 0, 6, 4, 7, 0),
    gsSP2Triangles(7, 3, 8, 0, 5, 8, 3, 0),
    gsSP2Triangles(6, 7, 9, 0, 7, 8, 9, 0),
    gsSP2Triangles(6, 10, 5, 0, 8, 11, 9, 0),
    gsSP2Triangles(8, 5, 11, 0, 6, 9, 12, 0),
    gsSP2Triangles(11, 12, 9, 0, 12, 10, 6, 0),
    gsSP2Triangles(5, 12, 11, 0, 5, 10, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 13, 15, 0),
    gsSP2Triangles(13, 17, 14, 0, 17, 13, 16, 0),
    gsSP2Triangles(18, 16, 15, 0, 16, 19, 17, 0),
    gsSP2Triangles(20, 16, 18, 0, 19, 16, 20, 0),
    gsSP2Triangles(18, 15, 21, 0, 18, 21, 20, 0),
    gsSP2Triangles(22, 21, 15, 0, 22, 15, 14, 0),
    gsSP2Triangles(23, 20, 21, 0, 22, 24, 21, 0),
    gsSP2Triangles(23, 21, 24, 0, 25, 20, 23, 0),
    gsSP2Triangles(23, 24, 26, 0, 25, 27, 20, 0),
    gsSP2Triangles(27, 19, 20, 0, 28, 25, 23, 0),
    gsSP2Triangles(28, 23, 26, 0, 27, 25, 29, 0),
    gsSP2Triangles(29, 25, 30, 0, 28, 30, 25, 0),
    gsSP2Triangles(27, 29, 31, 0, 31, 29, 30, 0),

    gsSPVertex(vtx_cliff_3+32, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 5, 0, 0, 5, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(0, 2, 8, 0, 2, 9, 8, 0),
    gsSP2Triangles(10, 9, 2, 0, 8, 11, 0, 0),
    gsSP2Triangles(12, 9, 10, 0, 12, 10, 13, 0),
    gsSP2Triangles(9, 14, 8, 0, 8, 14, 11, 0),
    gsSP2Triangles(15, 9, 12, 0, 9, 15, 14, 0),
    gsSP2Triangles(16, 12, 13, 0, 13, 17, 16, 0),
    gsSP2Triangles(15, 12, 18, 0, 12, 16, 18, 0),
    gsSP2Triangles(14, 15, 19, 0, 15, 18, 19, 0),
    gsSP2Triangles(20, 11, 14, 0, 20, 14, 19, 0),
    gsSP2Triangles(21, 0, 11, 0, 20, 21, 11, 0),
    gsSP2Triangles(0, 21, 5, 0, 20, 19, 22, 0),
    gsSP2Triangles(21, 20, 23, 0, 20, 22, 23, 0),
    gsSP2Triangles(21, 24, 5, 0, 19, 25, 22, 0),
    gsSP2Triangles(19, 18, 25, 0, 24, 26, 5, 0),
    gsSP2Triangles(26, 6, 5, 0, 24, 27, 26, 0),
    gsSP2Triangles(27, 6, 26, 0, 21, 28, 24, 0),
    gsSP2Triangles(24, 28, 27, 0, 29, 28, 21, 0),
    gsSP2Triangles(21, 23, 29, 0, 30, 27, 28, 0),
    gsSP1Triangle(31, 29, 23, 0),

    gsSPVertex(vtx_cliff_3+64, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(1, 4, 2, 0, 5, 6, 3, 0),
    gsSP2Triangles(1, 3, 6, 0, 1, 6, 4, 0),
    gsSP2Triangles(5, 7, 6, 0, 4, 8, 9, 0),
    gsSP2Triangles(9, 8, 10, 0, 11, 4, 6, 0),
    gsSP2Triangles(4, 11, 8, 0, 7, 12, 6, 0),
    gsSP2Triangles(11, 6, 12, 0, 12, 7, 13, 0),
    gsSP2Triangles(11, 14, 8, 0, 8, 15, 10, 0),
    gsSP2Triangles(8, 14, 15, 0, 15, 16, 10, 0),
    gsSP2Triangles(11, 17, 14, 0, 15, 14, 17, 0),
    gsSP2Triangles(11, 12, 18, 0, 11, 18, 17, 0),
    gsSP2Triangles(18, 12, 17, 0, 19, 16, 15, 0),
    gsSP2Triangles(19, 15, 17, 0, 12, 20, 17, 0),
    gsSP2Triangles(19, 17, 21, 0, 20, 21, 17, 0),
    gsSP2Triangles(21, 20, 19, 0, 12, 22, 20, 0),
    gsSP2Triangles(13, 22, 12, 0, 23, 19, 20, 0),
    gsSP2Triangles(24, 20, 22, 0, 23, 20, 24, 0),
    gsSP2Triangles(19, 25, 16, 0, 16, 25, 26, 0),
    gsSP2Triangles(25, 27, 26, 0, 19, 28, 25, 0),
    gsSP2Triangles(25, 29, 27, 0, 28, 19, 30, 0),
    gsSP2Triangles(23, 30, 19, 0, 31, 25, 28, 0),
    gsSP1Triangle(25, 31, 29, 0),

    gsSPVertex(vtx_cliff_3+96, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 5, 0, 6, 5, 4, 0),
    gsSP2Triangles(2, 3, 7, 0, 5, 7, 3, 0),
    gsSP2Triangles(0, 2, 8, 0, 7, 8, 2, 0),
    gsSP2Triangles(8, 9, 0, 0, 10, 0, 9, 0),
    gsSP2Triangles(7, 11, 8, 0, 7, 5, 11, 0),
    gsSP2Triangles(8, 12, 9, 0, 8, 13, 12, 0),
    gsSP2Triangles(8, 11, 13, 0, 9, 12, 14, 0),
    gsSP2Triangles(12, 13, 15, 0, 12, 15, 14, 0),
    gsSP2Triangles(15, 13, 16, 0, 16, 13, 11, 0),
    gsSP2Triangles(15, 16, 17, 0, 16, 11, 17, 0),
    gsSP2Triangles(18, 14, 15, 0, 15, 17, 18, 0),
    gsSP2Triangles(14, 19, 9, 0, 10, 9, 19, 0),
    gsSP2Triangles(14, 20, 19, 0, 20, 14, 18, 0),
    gsSP2Triangles(21, 19, 20, 0, 21, 10, 19, 0),
    gsSP2Triangles(20, 18, 21, 0, 22, 10, 21, 0),
    gsSP2Triangles(23, 10, 22, 0, 23, 22, 24, 0),
    gsSP2Triangles(22, 25, 24, 0, 25, 22, 21, 0),
    gsSP2Triangles(24, 25, 26, 0, 25, 21, 26, 0),
    gsSP2Triangles(26, 21, 27, 0, 21, 18, 27, 0),
    gsSP2Triangles(18, 28, 27, 0, 18, 17, 28, 0),
    gsSP2Triangles(28, 29, 27, 0, 28, 17, 30, 0),
    gsSP2Triangles(30, 29, 28, 0, 31, 30, 17, 0),
    gsSP1Triangle(17, 11, 31, 0),

    gsSPVertex(vtx_cliff_3+128, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 1, 5, 0, 4, 2, 1, 0),
    gsSP2Triangles(2, 6, 3, 0, 7, 3, 6, 0),
    gsSP2Triangles(2, 4, 8, 0, 2, 8, 6, 0),
    gsSP2Triangles(9, 4, 5, 0, 8, 4, 9, 0),
    gsSP2Triangles(9, 5, 10, 0, 8, 11, 6, 0),
    gsSP2Triangles(11, 7, 6, 0, 12, 9, 10, 0),
    gsSP2Triangles(12, 10, 13, 0, 14, 8, 9, 0),
    gsSP2Triangles(15, 9, 12, 0, 9, 15, 14, 0),
    gsSP2Triangles(12, 13, 16, 0, 15, 12, 16, 0),
    gsSP2Triangles(17, 8, 14, 0, 17, 11, 8, 0),
    gsSP2Triangles(14, 15, 18, 0, 15, 16, 19, 0),
    gsSP2Triangles(15, 19, 18, 0, 20, 19, 16, 0),
    gsSP2Triangles(16, 13, 20, 0, 21, 18, 19, 0),
    gsSP2Triangles(20, 21, 19, 0, 14, 18, 22, 0),
    gsSP2Triangles(17, 14, 22, 0, 13, 23, 20, 0),
    gsSP2Triangles(23, 13, 7, 0, 23, 24, 20, 0),
    gsSP2Triangles(7, 24, 23, 0, 20, 24, 25, 0),
    gsSP2Triangles(20, 25, 21, 0, 26, 24, 7, 0),
    gsSP2Triangles(25, 24, 26, 0, 11, 26, 7, 0),
    gsSP2Triangles(25, 27, 21, 0, 18, 21, 27, 0),
    gsSP2Triangles(25, 28, 27, 0, 28, 25, 26, 0),
    gsSP2Triangles(29, 18, 27, 0, 22, 18, 29, 0),
    gsSP2Triangles(30, 27, 28, 0, 29, 27, 30, 0),
    gsSP2Triangles(31, 22, 29, 0, 31, 17, 22, 0),

    gsSPVertex(vtx_cliff_3+160, 21, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 1, 5, 0, 0, 5, 1, 0),
    gsSP2Triangles(4, 6, 7, 0, 6, 8, 7, 0),
    gsSP2Triangles(9, 5, 0, 0, 9, 0, 3, 0),
    gsSP2Triangles(4, 5, 10, 0, 9, 10, 5, 0),
    gsSP2Triangles(6, 4, 10, 0, 10, 9, 11, 0),
    gsSP2Triangles(9, 3, 11, 0, 6, 10, 12, 0),
    gsSP2Triangles(8, 6, 12, 0, 10, 13, 12, 0),
    gsSP2Triangles(10, 11, 13, 0, 8, 12, 14, 0),
    gsSP2Triangles(13, 14, 12, 0, 8, 14, 15, 0),
    gsSP2Triangles(15, 14, 13, 0, 8, 15, 16, 0),
    gsSP2Triangles(13, 11, 17, 0, 17, 15, 13, 0),
    gsSP2Triangles(18, 17, 11, 0, 18, 11, 3, 0),
    gsSP2Triangles(18, 3, 17, 0, 3, 16, 19, 0),
    gsSP2Triangles(19, 17, 3, 0, 19, 16, 15, 0),
    gsSP2Triangles(19, 20, 17, 0, 19, 15, 20, 0),
    gsSP1Triangle(17, 20, 15, 0),
    gsSPEndDisplayList(),
};

