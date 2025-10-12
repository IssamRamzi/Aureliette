//
// Created by issbe on 23/09/2025.
//
#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H
#include "InputManager.h"
#include "math/kMath.h"
#include "core/Logger.h"

inline Logger logger("logs.txt");


typedef Vec2<float> vec2_f;
typedef Vec3<float> vec3_f;
typedef Vec4<float> vec4_f;
typedef Vec2<int> vec2_i;
typedef Vec3<int> vec3_i;
typedef Vec4<int> vec4_i;

typedef Matrix4<float> mat4_f;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;

typedef uint8_t ui8;
typedef uint16_t ui16;
typedef uint32_t ui32;


#endif //GLOBALS_H
