//
// Created by issbe on 28/09/2025.
//
#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <vector>

#include "Mesh.h"
#include "Vertex.h"
#include "Ogl/GLBuffer.h"
#include "Ogl/GLIndexBuffer.h"
#include "Ogl/GLShader.h"
#include "Ogl/GLVertexArrayBuffer.h"




class Triangle {
private:
    vec3_f m_position;
    Mesh* m_mesh;
public:
    Triangle(vec3_f pos, Mesh *mesh) : m_position(pos), m_mesh(mesh) {}

    ~Triangle() {
    }
    void Draw(GLShader& shader, bool rotate = false) {
        mat4_f modelMatrix{1};
        if (rotate)
            modelMatrix = mat4_f::translation(m_position) * mat4_f::rotation(180,{1.0,0.0,0.0});
        else
            modelMatrix = mat4_f::translation(m_position);

        shader.SetUniformMat4("model", modelMatrix);
        m_mesh->Draw();
    }
};

#endif //TRIANGLE_H
