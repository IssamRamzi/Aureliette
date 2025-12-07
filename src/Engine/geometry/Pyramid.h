//
// Created by issbe on 28/09/2025.
//

#ifndef PYRAMID_H
#define PYRAMID_H
#include <vector>

#include "Mesh.h"
#include "Vertex.h"
#include "Ogl/GLBuffer.h"
#include "Ogl/GLIndexBuffer.h"
#include "Ogl/GLShader.h"
#include "Ogl/GLVertexArrayBuffer.h"


class Pyramid {
private:
    vec3_f m_position;
    Mesh* m_mesh;

    std::vector<Vertex> vertices = {
        Vertex{ {-0.5f, -0.5f, -0.5f}, {1.0f, 0.0f, 0.0f} },
        Vertex{ { 0.5f, -0.5f, -0.5f}, {0.0f, 1.0f, 0.0f} },
        Vertex{ { 0.5f, -0.5f,  0.5f}, {0.0f, 0.0f, 1.0f} },
        Vertex{ {-0.5f, -0.5f,  0.5f}, {1.0f, 0.0f, 0.0f} },
        Vertex{ { 0.0f,  0.5f,  0.0f}, {0.5f, 0.5f, 0.5f} }
    };

    std::vector<GLuint> indices = {
        0, 1, 2,
        0, 2, 3,
        3, 2, 4,
        2, 1, 4,
        1, 0, 4,
        0, 3, 4
    };

public:
    Pyramid(vec3_f pos, Mesh* mesh = nullptr) : m_position(pos) {
        if (mesh) {
            m_mesh = mesh;
        } else {
            m_mesh = new Mesh{vertices, indices, {}}; // use members here
        }
    }


    ~Pyramid() {
    }
    void Draw(GLShader& shader, bool rotate = false) {
        mat4_f modelMatrix{1};
        if (rotate) {
            modelMatrix = mat4_f::translation(m_position) * mat4_f::rotation((float)glfwGetTime() * 10,{0.0,0.0,0.0});
        }
        else
            modelMatrix = mat4_f::translation(m_position);

        shader.SetUniformMat4("model", modelMatrix);
        m_mesh->Draw();
    }
};

#endif //PYRAMID_H
