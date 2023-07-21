// Generated by Arabiki64 V1.3
// By Buu342


// Custom combine mode to allow mixing primitive and vertex colors
#ifndef G_CC_PRIMLITE
    #define G_CC_PRIMLITE SHADE,0,PRIMITIVE,0,0,0,0,PRIMITIVE
#endif


/*********************************
              Models
*********************************/

static Vtx vtx_sea[] = {
    {1018, 59, -3, 0, 0, 0, 4, 5, 127, 255}, /* 0 */
    {960, 10, 8, 0, 0, 0, 1, 6, 127, 255}, /* 1 */
    {1018, 5, 8, 0, 0, 0, 0, 5, 127, 255}, /* 2 */
    {1018, -51, 2, 0, 0, 0, 1, 1, 127, 255}, /* 3 */
    {890, 56, 1, 0, 0, 0, 0, 7, 127, 255}, /* 4 */
    {1018, 110, 3, 0, 0, 0, 3, 8, 127, 255}, /* 5 */
    {684, 8, 9, 0, 0, 0, 1, -2, 127, 255}, /* 6 */
    {824, -38, 3, 0, 0, 0, -1, 1, 127, 255}, /* 7 */
    {769, 59, -2, 0, 0, 0, 0, 5, 127, 255}, /* 8 */
    {959, -99, 9, 0, 0, 0, 1, -2, 127, 255}, /* 9 */
    {1018, -109, 9, 0, 0, 0, -1, -10, 127, 255}, /* 10 */
    {1018, -164, -4, 0, 0, 0, 4, -10, 127, 255}, /* 11 */
    {738, 99, 3, 0, 0, 0, 4, 6, 127, 255}, /* 12 */
    {610, 38, 8, 0, 0, 0, -2, 5, 127, 255}, /* 13 */
    {573, -27, 1, 0, 0, 0, 4, -3, 127, 255}, /* 14 */
    {825, 134, -9, 0, 0, 0, -1, 24, 125, 255}, /* 15 */
    {935, 149, -2, 0, 0, 0, -1, 16, 126, 255}, /* 16 */
    {1018, 166, -11, 0, 0, 0, 5, 23, 125, 255}, /* 17 */
    {836, 203, -11, 0, 0, 0, 0, 14, 126, 255}, /* 18 */
    {1018, 229, -17, 0, 0, 0, 2, 18, 126, 255}, /* 19 */
    {741, 206, -10, 0, 0, 0, 3, 17, 126, 255}, /* 20 */
    {699, 142, 0, 0, 0, 0, 0, 13, 126, 255}, /* 21 */
    {777, 295, -26, 0, 0, 0, 1, 25, 124, 255}, /* 22 */
    {1018, 321, -35, 0, 0, 0, 2, 25, 124, 255}, /* 23 */
    {673, 237, -15, 0, 0, 0, 0, 19, 126, 255}, /* 24 */
    {617, 97, -2, 0, 0, 0, 3, 1, 127, 255}, /* 25 */
    {549, 143, -9, 0, 0, 0, -1, 19, 126, 255}, /* 26 */
    {556, 103, 4, 0, 0, 0, -1, 16, 126, 255}, /* 27 */
    {489, 54, 7, 0, 0, 0, 0, 7, 127, 255}, /* 28 */
    {523, 6, 1, 0, 0, 0, 2, -3, 127, 255}, /* 29 */
    {488, 120, -7, 0, 0, 0, 0, 10, 127, 255}, /* 30 */
    {384, 14, 9, 0, 0, 0, 0, -1, 127, 255}, /* 31 */
    {488, 120, -7, 0, 0, 0, 0, 10, 127, 255}, /* 32 */
    {340, 76, 3, 0, 0, 0, 0, 9, 127, 255}, /* 33 */
    {489, 54, 7, 0, 0, 0, 0, 7, 127, 255}, /* 34 */
    {384, 14, 9, 0, 0, 0, 0, -1, 127, 255}, /* 35 */
    {396, 148, 1, 0, 0, 0, 2, 1, 127, 255}, /* 36 */
    {549, 143, -9, 0, 0, 0, -1, 19, 126, 255}, /* 37 */
    {317, 129, 0, 0, 0, 0, 2, 5, 127, 255}, /* 38 */
    {535, 220, -10, 0, 0, 0, 3, 14, 126, 255}, /* 39 */
    {673, 237, -15, 0, 0, 0, 0, 19, 126, 255}, /* 40 */
    {777, 295, -26, 0, 0, 0, 1, 25, 124, 255}, /* 41 */
    {371, 180, -7, 0, 0, 0, 3, 15, 126, 255}, /* 42 */
    {227, 190, -2, 0, 0, 0, 1, 11, 127, 255}, /* 43 */
    {389, 242, -13, 0, 0, 0, 2, 17, 126, 255}, /* 44 */
    {342, 302, -17, 0, 0, 0, 3, 104, 72, 255}, /* 45 */
    {-321, 309, -18, 0, 0, 0, -2, 97, 83, 255}, /* 46 */
    {1018, 321, -35, 0, 0, 0, 2, 25, 124, 255}, /* 47 */
    {175, 276, -13, 0, 0, 0, 0, 18, 126, 255}, /* 48 */
    {80, 213, -5, 0, 0, 0, -1, 12, 126, 255}, /* 49 */
    {-911, 302, -30, 0, 0, 0, -1, 29, 124, 255}, /* 50 */
    {-1018, 321, -35, 0, 0, 0, -2, 26, 124, 255}, /* 51 */
    {-1018, 224, -16, 0, 0, 0, -2, 20, 125, 255}, /* 52 */
    {-291, 260, -12, 0, 0, 0, 0, 13, 126, 255}, /* 53 */
    {-755, 235, -16, 0, 0, 0, -1, 20, 125, 255}, /* 54 */
    {129, 142, 0, 0, 0, 0, -1, 7, 127, 255}, /* 55 */
    {-130, 168, -5, 0, 0, 0, 0, 20, 125, 255}, /* 56 */
    {-340, 213, -8, 0, 0, 0, -1, 14, 126, 255}, /* 57 */
    {215, 95, 6, 0, 0, 0, -1, 1, 127, 255}, /* 58 */
    {-65, 127, 5, 0, 0, 0, -1, 15, 126, 255}, /* 59 */
    {280, 46, 1, 0, 0, 0, 0, 7, 127, 255}, /* 60 */
    {66, 81, 1, 0, 0, 0, 5, 16, 126, 255}, /* 61 */
    {272, 4, 9, 0, 0, 0, -3, 9, 127, 255}, /* 62 */
    {-27, 79, 7, 0, 0, 0, -1, -6, 127, 255}, /* 63 */
    {-130, 168, -5, 0, 0, 0, 0, 20, 125, 255}, /* 64 */
    {-275, 145, 2, 0, 0, 0, 1, 6, 127, 255}, /* 65 */
    {-65, 127, 5, 0, 0, 0, -1, 15, 126, 255}, /* 66 */
    {-340, 213, -8, 0, 0, 0, -1, 14, 126, 255}, /* 67 */
    {-27, 79, 7, 0, 0, 0, -1, -6, 127, 255}, /* 68 */
    {-101, 67, 1, 0, 0, 0, 1, -4, 127, 255}, /* 69 */
    {-234, 102, -2, 0, 0, 0, 1, 6, 127, 255}, /* 70 */
    {-400, 180, -6, 0, 0, 0, 1, 15, 126, 255}, /* 71 */
    {61, 23, 0, 0, 0, 0, -2, -5, 127, 255}, /* 72 */
    {272, 4, 9, 0, 0, 0, -3, 9, 127, 255}, /* 73 */
    {-370, 130, 3, 0, 0, 0, -1, 9, 127, 255}, /* 74 */
    {-520, 190, -5, 0, 0, 0, -2, 15, 126, 255}, /* 75 */
    {-321, 309, -18, 0, 0, 0, -2, 97, 83, 255}, /* 76 */
    {-523, 239, -13, 0, 0, 0, -2, 17, 126, 255}, /* 77 */
    {-755, 235, -16, 0, 0, 0, -1, 20, 125, 255}, /* 78 */
    {-624, 165, -6, 0, 0, 0, -4, 17, 126, 255}, /* 79 */
    {-602, 112, 3, 0, 0, 0, 2, 5, 127, 255}, /* 80 */
    {-792, 157, -2, 0, 0, 0, 1, 13, 126, 255}, /* 81 */
    {-1018, 224, -16, 0, 0, 0, -2, 20, 125, 255}, /* 82 */
    {-1018, 165, -10, 0, 0, 0, -4, 24, 125, 255}, /* 83 */
    {-1018, 132, 0, 0, 0, 0, -2, 16, 126, 255}, /* 84 */
    {-715, 103, -2, 0, 0, 0, -1, 16, 126, 255}, /* 85 */
    {-861, 118, 0, 0, 0, 0, 0, 13, 126, 255}, /* 86 */
    {-1018, 74, -1, 0, 0, 0, -5, 16, 126, 255}, /* 87 */
    {-864, 97, 4, 0, 0, 0, -1, 10, 127, 255}, /* 88 */
    {-1018, 39, 7, 0, 0, 0, 1, -5, 127, 255}, /* 89 */
    {-732, 54, 8, 0, 0, 0, 1, 5, 127, 255}, /* 90 */
    {-859, 43, -2, 0, 0, 0, -5, 7, 127, 255}, /* 91 */
    {-1018, 15, 1, 0, 0, 0, 5, -4, 127, 255}, /* 92 */
    {-985, -31, 7, 0, 0, 0, 1, 2, 127, 255}, /* 93 */
    {-1018, -32, 10, 0, 0, 0, 9, 1, 127, 255}, /* 94 */
    {-1018, -80, 2, 0, 0, 0, 0, 1, 127, 255}, /* 95 */
    {-859, 43, -2, 0, 0, 0, -5, 7, 127, 255}, /* 96 */
    {-985, -31, 7, 0, 0, 0, 1, 2, 127, 255}, /* 97 */
    {-944, -30, 9, 0, 0, 0, -5, 3, 127, 255}, /* 98 */
    {-732, 54, 8, 0, 0, 0, 1, 5, 127, 255}, /* 99 */
    {-871, -83, 3, 0, 0, 0, -3, 4, 127, 255}, /* 100 */
    {-1018, -80, 2, 0, 0, 0, 0, 1, 127, 255}, /* 101 */
    {-803, -98, 8, 0, 0, 0, -1, -9, 127, 255}, /* 102 */
    {-1018, -123, 7, 0, 0, 0, -3, -1, 127, 255}, /* 103 */
    {-789, -66, 10, 0, 0, 0, -2, 4, 127, 255}, /* 104 */
    {-840, -30, 2, 0, 0, 0, 7, 5, 127, 255}, /* 105 */
    {-704, 12, 2, 0, 0, 0, -3, -1, 127, 255}, /* 106 */
    {-730, -80, 8, 0, 0, 0, 5, 10, 127, 255}, /* 107 */
    {-807, -152, 1, 0, 0, 0, 1, -10, 127, 255}, /* 108 */
    {-849, -215, 3, 0, 0, 0, 2, -6, 127, 255}, /* 109 */
    {-1018, -170, 0, 0, 0, 0, -5, -16, 126, 255}, /* 110 */
    {-952, -215, -4, 0, 0, 0, -6, -11, 126, 255}, /* 111 */
    {-1018, -321, -9, 0, 0, 0, -2, -9, 127, 255}, /* 112 */
    {-774, -199, -5, 0, 0, 0, 1, -4, 127, 255}, /* 113 */
    {-583, -287, -6, 0, 0, 0, -3, -37, 121, 255}, /* 114 */
    {1018, -321, -9, 0, 0, 0, 3, -8, 127, 255}, /* 115 */
    {-708, -172, 7, 0, 0, 0, -3, -11, 127, 255}, /* 116 */
    {24, -299, 6, 0, 0, 0, -1, -14, 126, 255}, /* 117 */
    {-588, -150, -4, 0, 0, 0, 3, 2, 127, 255}, /* 118 */
    {491, -264, 7, 0, 0, 0, 1, 2, 127, 255}, /* 119 */
    {-562, -76, -4, 0, 0, 0, -3, -11, 126, 255}, /* 120 */
    {922, -210, -1, 0, 0, 0, 3, -8, 127, 255}, /* 121 */
    {1018, -208, -3, 0, 0, 0, 4, -3, 127, 255}, /* 122 */
    {-708, -28, 9, 0, 0, 0, -1, 7, 127, 255}, /* 123 */
    {-544, -13, 9, 0, 0, 0, -4, -8, 127, 255}, /* 124 */
    {835, -158, 5, 0, 0, 0, -2, -5, 127, 255}, /* 125 */
    {1018, -164, -4, 0, 0, 0, 4, -10, 127, 255}, /* 126 */
    {959, -99, 9, 0, 0, 0, 1, -2, 127, 255}, /* 127 */
    {-530, 5, 9, 0, 0, 0, 0, 11, 127, 255}, /* 128 */
    {-704, 12, 2, 0, 0, 0, -3, -1, 127, 255}, /* 129 */
    {-544, -13, 9, 0, 0, 0, -4, -8, 127, 255}, /* 130 */
    {-732, 54, 8, 0, 0, 0, 1, 5, 127, 255}, /* 131 */
    {959, -99, 9, 0, 0, 0, 1, -2, 127, 255}, /* 132 */
    {836, -98, 2, 0, 0, 0, -3, -14, 126, 255}, /* 133 */
    {835, -158, 5, 0, 0, 0, -2, -5, 127, 255}, /* 134 */
    {-578, 60, -3, 0, 0, 0, 3, 11, 126, 255}, /* 135 */
    {-602, 112, 3, 0, 0, 0, 2, 5, 127, 255}, /* 136 */
    {811, -68, 9, 0, 0, 0, -2, 6, 127, 255}, /* 137 */
    {824, -38, 3, 0, 0, 0, -1, 1, 127, 255}, /* 138 */
    {-537, 109, -2, 0, 0, 0, -1, 4, 127, 255}, /* 139 */
    {-520, 190, -5, 0, 0, 0, -2, 15, 126, 255}, /* 140 */
    {-370, 130, 3, 0, 0, 0, -1, 9, 127, 255}, /* 141 */
    {-500, 16, 8, 0, 0, 0, 1, 2, 127, 255}, /* 142 */
    {-463, 102, 4, 0, 0, 0, -3, 15, 126, 255}, /* 143 */
    {-387, 71, 0, 0, 0, 0, 2, -5, 127, 255}, /* 144 */
    {-282, 64, 7, 0, 0, 0, 0, -3, 127, 255}, /* 145 */
    {-234, 102, -2, 0, 0, 0, 1, 6, 127, 255}, /* 146 */
    {-338, -24, -5, 0, 0, 0, -3, 22, 125, 255}, /* 147 */
    {-335, 15, -4, 0, 0, 0, -2, -7, 127, 255}, /* 148 */
    {-177, 55, 7, 0, 0, 0, 3, 14, 126, 255}, /* 149 */
    {-101, 67, 1, 0, 0, 0, 1, -4, 127, 255}, /* 150 */
    {-186, -28, 9, 0, 0, 0, -1, -3, 127, 255}, /* 151 */
    {-65, 32, -3, 0, 0, 0, 0, 2, 127, 255}, /* 152 */
    {61, 23, 0, 0, 0, 0, -2, -5, 127, 255}, /* 153 */
    {-399, -56, 4, 0, 0, 0, 4, 18, 126, 255}, /* 154 */
    {-415, -87, 9, 0, 0, 0, -1, 1, 127, 255}, /* 155 */
    {-562, -76, -4, 0, 0, 0, -3, -11, 126, 255}, /* 156 */
    {-125, -38, 8, 0, 0, 0, 2, 5, 127, 255}, /* 157 */
    {-433, -115, 7, 0, 0, 0, -2, -10, 127, 255}, /* 158 */
    {-588, -150, -4, 0, 0, 0, 3, 2, 127, 255}, /* 159 */
    {-186, -28, 9, 0, 0, 0, -1, -3, 127, 255}, /* 160 */
    {-415, -87, 9, 0, 0, 0, -1, 1, 127, 255}, /* 161 */
    {-274, -78, 2, 0, 0, 0, 2, -6, 127, 255}, /* 162 */
    {-125, -38, 8, 0, 0, 0, 2, 5, 127, 255}, /* 163 */
    {-277, -119, 7, 0, 0, 0, 0, -9, 127, 255}, /* 164 */
    {-433, -115, 7, 0, 0, 0, -2, -10, 127, 255}, /* 165 */
    {-588, -150, -4, 0, 0, 0, 3, 2, 127, 255}, /* 166 */
    {-499, -156, 4, 0, 0, 0, -6, -5, 127, 255}, /* 167 */
    {-151, -75, 8, 0, 0, 0, 0, -5, 127, 255}, /* 168 */
    {-351, -158, -5, 0, 0, 0, 1, -15, 126, 255}, /* 169 */
    {-105, -91, 5, 0, 0, 0, -1, -2, 127, 255}, /* 170 */
    {-564, -189, -3, 0, 0, 0, 2, 12, 126, 255}, /* 171 */
    {-708, -172, 7, 0, 0, 0, -3, -11, 127, 255}, /* 172 */
    {-419, -212, -1, 0, 0, 0, 5, 7, 127, 255}, /* 173 */
    {-566, -243, 9, 0, 0, 0, 0, -11, 127, 255}, /* 174 */
    {-583, -287, -6, 0, 0, 0, -3, -37, 121, 255}, /* 175 */
    {-200, -241, -6, 0, 0, 0, -2, 3, 127, 255}, /* 176 */
    {24, -299, 6, 0, 0, 0, -1, -14, 126, 255}, /* 177 */
    {-254, -150, 0, 0, 0, 0, -2, -17, 126, 255}, /* 178 */
    {238, -223, -3, 0, 0, 0, -3, 5, 127, 255}, /* 179 */
    {491, -264, 7, 0, 0, 0, 1, 2, 127, 255}, /* 180 */
    {-151, -177, 3, 0, 0, 0, -1, -10, 127, 255}, /* 181 */
    {143, -187, -4, 0, 0, 0, 0, -15, 126, 255}, /* 182 */
    {73, -163, 3, 0, 0, 0, -1, -11, 127, 255}, /* 183 */
    {303, -198, 1, 0, 0, 0, -3, -5, 127, 255}, /* 184 */
    {274, -152, 3, 0, 0, 0, -2, -12, 126, 255}, /* 185 */
    {-15, -137, -3, 0, 0, 0, 0, -5, 127, 255}, /* 186 */
    {448, -213, -4, 0, 0, 0, 3, 6, 127, 255}, /* 187 */
    {-60, -88, 8, 0, 0, 0, -3, 10, 127, 255}, /* 188 */
    {173, -116, 7, 0, 0, 0, 0, -1, 127, 255}, /* 189 */
    {-14, -53, 2, 0, 0, 0, 1, -6, 127, 255}, /* 190 */
    {127, -71, 4, 0, 0, 0, -1, -6, 127, 255}, /* 191 */
    {-14, -53, 2, 0, 0, 0, 1, -6, 127, 255}, /* 192 */
    {32, -24, 9, 0, 0, 0, 0, 2, 127, 255}, /* 193 */
    {-125, -38, 8, 0, 0, 0, 2, 5, 127, 255}, /* 194 */
    {127, -71, 4, 0, 0, 0, -1, -6, 127, 255}, /* 195 */
    {-65, 32, -3, 0, 0, 0, 0, 2, 127, 255}, /* 196 */
    {61, 23, 0, 0, 0, 0, -2, -5, 127, 255}, /* 197 */
    {152, -15, 0, 0, 0, 0, -3, 9, 127, 255}, /* 198 */
    {272, 4, 9, 0, 0, 0, -3, 9, 127, 255}, /* 199 */
    {156, -51, 9, 0, 0, 0, 0, -4, 127, 255}, /* 200 */
    {281, -23, 9, 0, 0, 0, -2, -5, 127, 255}, /* 201 */
    {384, 14, 9, 0, 0, 0, 0, -1, 127, 255}, /* 202 */
    {260, -67, 2, 0, 0, 0, -1, -6, 127, 255}, /* 203 */
    {173, -116, 7, 0, 0, 0, 0, -1, 127, 255}, /* 204 */
    {400, -50, 0, 0, 0, 0, 0, 7, 127, 255}, /* 205 */
    {352, -79, 8, 0, 0, 0, 2, -3, 127, 255}, /* 206 */
    {331, -97, 5, 0, 0, 0, -1, -4, 127, 255}, /* 207 */
    {522, -49, 8, 0, 0, 0, 5, 7, 127, 255}, /* 208 */
    {573, -27, 1, 0, 0, 0, 4, -3, 127, 255}, /* 209 */
    {514, -79, 9, 0, 0, 0, 0, -12, 126, 255}, /* 210 */
    {574, -96, 4, 0, 0, 0, 3, 6, 127, 255}, /* 211 */
    {619, -58, -3, 0, 0, 0, 4, 3, 127, 255}, /* 212 */
    {704, -59, -4, 0, 0, 0, -4, 0, 127, 255}, /* 213 */
    {824, -38, 3, 0, 0, 0, -1, 1, 127, 255}, /* 214 */
    {811, -68, 9, 0, 0, 0, -2, 6, 127, 255}, /* 215 */
    {714, -115, 7, 0, 0, 0, 0, -5, 127, 255}, /* 216 */
    {744, -142, 1, 0, 0, 0, 2, -7, 127, 255}, /* 217 */
    {836, -98, 2, 0, 0, 0, -3, -14, 126, 255}, /* 218 */
    {835, -158, 5, 0, 0, 0, -2, -5, 127, 255}, /* 219 */
    {597, -122, 7, 0, 0, 0, -1, -2, 127, 255}, /* 220 */
    {779, -174, 2, 0, 0, 0, -2, -7, 127, 255}, /* 221 */
    {922, -210, -1, 0, 0, 0, 3, -8, 127, 255}, /* 222 */
    {496, -167, 4, 0, 0, 0, -1, -9, 127, 255}, /* 223 */
    {922, -210, -1, 0, 0, 0, 3, -8, 127, 255}, /* 224 */
    {779, -174, 2, 0, 0, 0, -2, -7, 127, 255}, /* 225 */
    {757, -215, -2, 0, 0, 0, -1, 10, 127, 255}, /* 226 */
    {496, -167, 4, 0, 0, 0, -1, -9, 127, 255}, /* 227 */
    {491, -264, 7, 0, 0, 0, 1, 2, 127, 255}, /* 228 */
    {448, -213, -4, 0, 0, 0, 3, 6, 127, 255}, /* 229 */
    {303, -198, 1, 0, 0, 0, -3, -5, 127, 255}, /* 230 */
    {274, -152, 3, 0, 0, 0, -2, -12, 126, 255}, /* 231 */
    {574, -96, 4, 0, 0, 0, 3, 6, 127, 255}, /* 232 */
    {441, -128, 1, 0, 0, 0, 2, 1, 127, 255}, /* 233 */
    {331, -97, 5, 0, 0, 0, -1, -4, 127, 255}, /* 234 */
    {303, -122, 6, 0, 0, 0, 0, -4, 127, 255}, /* 235 */
    {173, -116, 7, 0, 0, 0, 0, -1, 127, 255}, /* 236 */
};

static Gfx gfx_sea[] = {
    gsSPVertex(vtx_sea+0, 32, 0),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_PRIMLITE, G_CC_PRIMLITE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPSetGeometryMode(G_SHADE | G_ZBUFFER | G_CULL_BACK | G_SHADING_SMOOTH | G_LIGHTING),
    gsDPSetPrimColor(0, 0, 138, 240, 255, 255),
    gsDPPipeSync(),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(1, 0, 4, 0, 5, 4, 0, 0),
    gsSP2Triangles(1, 6, 3, 0, 1, 4, 6, 0),
    gsSP2Triangles(6, 7, 3, 0, 4, 8, 6, 0),
    gsSP2Triangles(9, 3, 7, 0, 3, 9, 10, 0),
    gsSP2Triangles(11, 10, 9, 0, 4, 12, 8, 0),
    gsSP2Triangles(5, 12, 4, 0, 6, 8, 13, 0),
    gsSP2Triangles(12, 13, 8, 0, 7, 6, 14, 0),
    gsSP2Triangles(6, 13, 14, 0, 5, 15, 12, 0),
    gsSP2Triangles(16, 15, 5, 0, 5, 17, 16, 0),
    gsSP2Triangles(17, 18, 16, 0, 15, 16, 18, 0),
    gsSP2Triangles(19, 18, 17, 0, 18, 20, 15, 0),
    gsSP2Triangles(19, 20, 18, 0, 12, 15, 21, 0),
    gsSP2Triangles(15, 20, 21, 0, 20, 19, 22, 0),
    gsSP2Triangles(19, 23, 22, 0, 20, 24, 21, 0),
    gsSP2Triangles(20, 22, 24, 0, 21, 25, 12, 0),
    gsSP2Triangles(12, 25, 13, 0, 21, 24, 26, 0),
    gsSP2Triangles(21, 27, 25, 0, 21, 26, 27, 0),
    gsSP2Triangles(25, 28, 13, 0, 27, 28, 25, 0),
    gsSP2Triangles(13, 28, 29, 0, 14, 13, 29, 0),
    gsSP2Triangles(30, 28, 27, 0, 26, 30, 27, 0),
    gsSP2Triangles(28, 31, 29, 0, 14, 29, 31, 0),

    gsSPVertex(vtx_sea+32, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 0, 5, 0, 0, 6, 1, 0),
    gsSP2Triangles(0, 4, 6, 0, 7, 5, 8, 0),
    gsSP2Triangles(7, 4, 5, 0, 9, 7, 8, 0),
    gsSP2Triangles(7, 10, 4, 0, 4, 10, 11, 0),
    gsSP2Triangles(7, 11, 10, 0, 4, 11, 6, 0),
    gsSP2Triangles(7, 9, 12, 0, 7, 12, 11, 0),
    gsSP2Triangles(9, 13, 12, 0, 12, 13, 11, 0),
    gsSP2Triangles(13, 9, 14, 0, 15, 14, 9, 0),
    gsSP2Triangles(13, 16, 11, 0, 13, 14, 16, 0),
    gsSP2Triangles(11, 16, 17, 0, 14, 15, 18, 0),
    gsSP2Triangles(15, 19, 18, 0, 19, 20, 18, 0),
    gsSP2Triangles(16, 14, 21, 0, 17, 16, 21, 0),
    gsSP2Triangles(22, 18, 20, 0, 18, 22, 14, 0),
    gsSP2Triangles(17, 23, 11, 0, 6, 11, 23, 0),
    gsSP2Triangles(24, 17, 21, 0, 17, 24, 23, 0),
    gsSP2Triangles(21, 14, 25, 0, 24, 21, 25, 0),
    gsSP2Triangles(6, 23, 26, 0, 1, 6, 26, 0),
    gsSP2Triangles(27, 23, 24, 0, 1, 26, 28, 0),
    gsSP2Triangles(1, 28, 3, 0, 26, 23, 29, 0),
    gsSP2Triangles(28, 26, 29, 0, 23, 27, 29, 0),
    gsSP2Triangles(28, 29, 30, 0, 3, 28, 30, 0),
    gsSP2Triangles(29, 27, 31, 0, 30, 29, 31, 0),

    gsSPVertex(vtx_sea+64, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(4, 2, 5, 0, 2, 1, 6, 0),
    gsSP2Triangles(5, 2, 6, 0, 3, 7, 1, 0),
    gsSP2Triangles(8, 4, 5, 0, 8, 9, 4, 0),
    gsSP2Triangles(1, 7, 10, 0, 1, 10, 6, 0),
    gsSP2Triangles(3, 11, 7, 0, 10, 7, 11, 0),
    gsSP2Triangles(3, 12, 13, 0, 11, 3, 13, 0),
    gsSP2Triangles(13, 12, 14, 0, 11, 13, 15, 0),
    gsSP2Triangles(15, 13, 14, 0, 11, 15, 16, 0),
    gsSP2Triangles(15, 14, 17, 0, 17, 14, 18, 0),
    gsSP2Triangles(17, 18, 19, 0, 17, 19, 20, 0),
    gsSP2Triangles(15, 17, 21, 0, 15, 21, 16, 0),
    gsSP2Triangles(17, 20, 22, 0, 17, 22, 21, 0),
    gsSP2Triangles(22, 20, 23, 0, 22, 23, 24, 0),
    gsSP2Triangles(24, 23, 25, 0, 21, 22, 26, 0),
    gsSP2Triangles(26, 22, 24, 0, 21, 26, 16, 0),
    gsSP2Triangles(24, 25, 27, 0, 27, 26, 24, 0),
    gsSP2Triangles(27, 25, 28, 0, 28, 29, 27, 0),
    gsSP2Triangles(28, 30, 29, 0, 29, 30, 31, 0),

    gsSPVertex(vtx_sea+96, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 1, 5, 0, 4, 2, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 5, 7, 0),
    gsSP2Triangles(4, 8, 2, 0, 6, 8, 4, 0),
    gsSP2Triangles(8, 9, 2, 0, 10, 2, 9, 0),
    gsSP2Triangles(10, 9, 8, 0, 3, 2, 10, 0),
    gsSP2Triangles(8, 6, 11, 0, 6, 7, 12, 0),
    gsSP2Triangles(6, 12, 11, 0, 12, 7, 13, 0),
    gsSP2Triangles(13, 7, 14, 0, 13, 14, 15, 0),
    gsSP2Triangles(15, 14, 16, 0, 15, 16, 13, 0),
    gsSP2Triangles(12, 13, 17, 0, 18, 13, 16, 0),
    gsSP2Triangles(18, 17, 13, 0, 19, 18, 16, 0),
    gsSP2Triangles(20, 12, 17, 0, 20, 17, 18, 0),
    gsSP2Triangles(12, 20, 11, 0, 19, 21, 18, 0),
    gsSP2Triangles(22, 11, 20, 0, 19, 23, 21, 0),
    gsSP2Triangles(24, 11, 22, 0, 24, 8, 11, 0),
    gsSP2Triangles(19, 25, 23, 0, 26, 25, 19, 0),
    gsSP2Triangles(27, 8, 24, 0, 10, 8, 27, 0),
    gsSP2Triangles(28, 27, 24, 0, 28, 10, 27, 0),
    gsSP2Triangles(26, 29, 25, 0, 26, 30, 29, 0),
    gsSP1Triangle(31, 29, 30, 0),

    gsSPVertex(vtx_sea+128, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 0, 7, 3, 0),
    gsSP2Triangles(8, 3, 7, 0, 4, 9, 5, 0),
    gsSP2Triangles(4, 10, 9, 0, 11, 8, 7, 0),
    gsSP2Triangles(12, 8, 11, 0, 13, 12, 11, 0),
    gsSP2Triangles(14, 11, 7, 0, 14, 7, 0, 0),
    gsSP2Triangles(13, 11, 15, 0, 15, 11, 14, 0),
    gsSP2Triangles(13, 15, 16, 0, 16, 15, 14, 0),
    gsSP2Triangles(17, 13, 16, 0, 17, 18, 13, 0),
    gsSP2Triangles(16, 14, 19, 0, 19, 14, 0, 0),
    gsSP2Triangles(20, 17, 16, 0, 16, 19, 20, 0),
    gsSP2Triangles(21, 18, 17, 0, 21, 17, 20, 0),
    gsSP2Triangles(21, 22, 18, 0, 23, 20, 19, 0),
    gsSP2Triangles(21, 20, 23, 0, 24, 22, 21, 0),
    gsSP2Triangles(24, 21, 23, 0, 25, 22, 24, 0),
    gsSP2Triangles(19, 26, 23, 0, 26, 19, 0, 0),
    gsSP2Triangles(26, 0, 27, 0, 23, 26, 27, 0),
    gsSP2Triangles(27, 0, 2, 0, 27, 2, 28, 0),
    gsSP2Triangles(29, 24, 23, 0, 30, 27, 28, 0),
    gsSP1Triangle(30, 28, 31, 0),

    gsSPVertex(vtx_sea+160, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 1, 5, 0, 4, 2, 1, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 2, 4, 0),
    gsSP2Triangles(8, 3, 2, 0, 9, 4, 5, 0),
    gsSP2Triangles(9, 5, 7, 0, 8, 4, 10, 0),
    gsSP2Triangles(7, 6, 11, 0, 11, 6, 12, 0),
    gsSP2Triangles(11, 13, 7, 0, 13, 9, 7, 0),
    gsSP2Triangles(14, 11, 12, 0, 14, 13, 11, 0),
    gsSP2Triangles(14, 12, 15, 0, 16, 13, 14, 0),
    gsSP2Triangles(16, 14, 15, 0, 9, 13, 16, 0),
    gsSP2Triangles(17, 16, 15, 0, 18, 4, 9, 0),
    gsSP2Triangles(16, 18, 9, 0, 10, 4, 18, 0),
    gsSP2Triangles(19, 16, 17, 0, 17, 20, 19, 0),
    gsSP2Triangles(16, 21, 18, 0, 10, 18, 21, 0),
    gsSP2Triangles(22, 16, 19, 0, 23, 21, 16, 0),
    gsSP2Triangles(22, 23, 16, 0, 24, 22, 19, 0),
    gsSP2Triangles(19, 20, 24, 0, 25, 23, 22, 0),
    gsSP2Triangles(24, 25, 22, 0, 23, 26, 21, 0),
    gsSP2Triangles(27, 24, 20, 0, 26, 28, 21, 0),
    gsSP2Triangles(28, 10, 21, 0, 23, 29, 26, 0),
    gsSP2Triangles(29, 28, 26, 0, 25, 29, 23, 0),
    gsSP2Triangles(30, 10, 28, 0, 30, 8, 10, 0),
    gsSP2Triangles(3, 8, 30, 0, 31, 30, 28, 0),
    gsSP1Triangle(29, 31, 28, 0),

    gsSPVertex(vtx_sea+192, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(1, 4, 2, 0, 5, 4, 1, 0),
    gsSP2Triangles(6, 5, 1, 0, 6, 7, 5, 0),
    gsSP2Triangles(3, 8, 1, 0, 6, 1, 8, 0),
    gsSP2Triangles(7, 6, 9, 0, 9, 6, 8, 0),
    gsSP2Triangles(10, 7, 9, 0, 11, 8, 3, 0),
    gsSP2Triangles(9, 8, 11, 0, 12, 11, 3, 0),
    gsSP2Triangles(10, 9, 13, 0, 14, 9, 11, 0),
    gsSP2Triangles(13, 9, 14, 0, 15, 11, 12, 0),
    gsSP2Triangles(14, 11, 15, 0, 16, 10, 13, 0),
    gsSP2Triangles(16, 17, 10, 0, 18, 13, 14, 0),
    gsSP2Triangles(16, 13, 18, 0, 18, 14, 19, 0),
    gsSP2Triangles(16, 18, 19, 0, 19, 14, 15, 0),
    gsSP2Triangles(20, 17, 16, 0, 20, 16, 19, 0),
    gsSP2Triangles(21, 17, 20, 0, 19, 21, 20, 0),
    gsSP2Triangles(22, 17, 21, 0, 22, 21, 23, 0),
    gsSP2Triangles(21, 24, 23, 0, 21, 19, 24, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 23, 25, 0),
    gsSP2Triangles(26, 25, 27, 0, 19, 28, 24, 0),
    gsSP2Triangles(24, 28, 25, 0, 27, 25, 29, 0),
    gsSP2Triangles(30, 27, 29, 0, 28, 31, 25, 0),
    gsSP2Triangles(29, 25, 31, 0, 28, 19, 31, 0),

    gsSPVertex(vtx_sea+224, 13, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(4, 0, 2, 0, 2, 5, 4, 0),
    gsSP2Triangles(3, 5, 2, 0, 3, 6, 5, 0),
    gsSP2Triangles(6, 3, 7, 0, 8, 9, 3, 0),
    gsSP2Triangles(8, 10, 9, 0, 3, 11, 7, 0),
    gsSP2Triangles(3, 9, 11, 0, 9, 10, 11, 0),
    gsSP2Triangles(11, 12, 7, 0, 11, 10, 12, 0),
    gsSPEndDisplayList(),
};

