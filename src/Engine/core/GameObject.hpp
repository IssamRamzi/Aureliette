#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Globals.h"
#include "geometry/Mesh.h"

class GameObject{
private:
    vec3_f m_position;
    vec3_f m_scale;
    vec3_f m_rotation;

    Mesh *m_mesh;
public:
    GameObject(vec3_f position, vec3_f scale, vec3_f rotation);
    GameObject(vec3_f position, vec3_f scale, vec3_f rotation, Mesh *mesh);

    mat4_f GetModelMatrix();

    void Draw();
    void Update();

};

#endif // GAMEOBJECT_H
