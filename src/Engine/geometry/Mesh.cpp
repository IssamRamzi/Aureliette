//
// Created by issbe on 28/09/2025.
//

#include "Mesh.h"

#include "Ogl/GLVertexArrayBuffer.h"
#include "Ogl/GLIndexBuffer.h"
#include "Ogl/GLShader.h"
#include "core/Texture.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indecies, std::vector<Texture> textures) : m_vertices(vertices), m_indecies(indecies), m_textures(textures) {
    VAO = new GLVertexArrayBuffer();
    VBO = new GLBuffer(vertices, 6);
    EBO = new GLIndexBuffer(indecies);
    VAO->AddBuffer(*VBO, 0, 3, sizeof(Vertex), (void*)0);                   // pos
    VAO->AddBuffer(*VBO, 1, 3, sizeof(Vertex), (void*)(3 * sizeof(float))); // col
    VAO->AddBuffer(*VBO, 2, 2, sizeof(Vertex), (void*)(6 * sizeof(float))); // texcoords
}

Mesh::~Mesh() {
    delete VAO;
    delete EBO;
    delete VBO;
}


void Mesh::Draw() {
    VAO->Bind();
    EBO->Bind();

    for (auto& texture : m_textures) {
        texture.Bind(0);
    }

    glDrawElements(GL_TRIANGLES, EBO->GetCount(), GL_UNSIGNED_INT, 0);

    for (auto& texture : m_textures) {
        texture.Unbind();
    }

    EBO->Unbind();
    VAO->Unbind();
}
