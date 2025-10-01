//
// Created by issbe on 23/09/2025.
//

#ifndef VERTEX_H
#define VERTEX_H
#include <vector>

#include "../core/Globals.h"
#include "math/kMath.h"

typedef struct {
    vec3_f position;
    vec3_f color;
    vec2_f texcoords;
} Vertex;
#endif //VERTEX_H
