//
// Created by issbe on 28/09/2025.
//

#ifndef CUBE_H
#define CUBE_H
#include <vector>

#include "Mesh.h"
#include "Vertex.h"
#include "Ogl/GLBuffer.h"
#include "Ogl/GLIndexBuffer.h"
#include "Ogl/GLShader.h"
#include "Ogl/GLVertexArrayBuffer.h"


class Cube {
private:
    vec3_f m_position;
    Mesh* m_mesh;

    std::vector<Vertex> vertices = {
		// FRONT
		{{-1.0f, -1.0f,  1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
		{{ 1.0f, -1.0f,  1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
		{{ 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f}},
		{{-1.0f,  1.0f,  1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f}},

		// BACK
		{{ 1.0f, -1.0f, -1.0f}, {1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
		{{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
		{{-1.0f,  1.0f, -1.0f}, {0.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
		{{ 1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},

		// LEFT
		{{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
		{{-1.0f, -1.0f,  1.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
		{{-1.0f,  1.0f,  1.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f}},
		{{-1.0f,  1.0f, -1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},

		// RIGHT
		{{ 1.0f, -1.0f,  1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
		{{ 1.0f, -1.0f, -1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
		{{ 1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
		{{ 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 0.0f}, {0.0f, 1.0f}},

		// TOP
		{{-1.0f,  1.0f,  1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
		{{ 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
		{{ 1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
		{{-1.0f,  1.0f, -1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},

		// BOTTOM
		{{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
		{{ 1.0f, -1.0f, -1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
		{{ 1.0f, -1.0f,  1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
		{{-1.0f, -1.0f,  1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
	};

	std::vector<GLuint> indices = {
		0, 1, 2, 0, 2, 3,
		4, 5, 6, 4, 6, 7,
		8, 9,10, 8,10,11,
		12,13,14, 12,14,15,
		16,17,18, 16,18,19,
		20,21,22, 20,22,23
	};

public:
    Cube(vec3_f pos, Mesh* mesh = nullptr) : m_position(pos) {
        if (mesh) {
            m_mesh = mesh;
        } else {
            m_mesh = new Mesh{vertices, indices, {}}; // use members here
        }
    }


    ~Cube() {
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

#endif //CUBE_H
