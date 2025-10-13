//
// Created by issbe on 28/09/2025.
//

#include "Mesh.h"

#include "Ogl/GLVertexArrayBuffer.h"
#include "Ogl/GLIndexBuffer.h"
#include "Ogl/GLShader.h"
#include "../../impl/Ogl/GLTexture.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indecies, std::vector<GLTexture> textures) : m_vertices(vertices), m_indecies(indecies), m_textures(textures) {
    VAO = new GLVertexArrayBuffer();
    VBO = new GLBuffer(vertices, 8);
    EBO = new GLIndexBuffer(indecies);
    VAO->AddBuffer(*VBO, 0, 3, sizeof(Vertex), (void*)0);                   // pos
    VAO->AddBuffer(*VBO, 1, 3, sizeof(Vertex), (void*)(offsetof(Vertex, color))); // col
    VAO->AddBuffer(*VBO, 2, 2, sizeof(Vertex), (void*)(offsetof(Vertex, texcoords))); // texcoords
}

Mesh::~Mesh() {
    delete VAO;
    delete EBO;
    delete VBO;
}


void Mesh::Draw() {
    VAO->Bind();
    EBO->Bind();

    for (size_t i = 0; i < m_textures.size(); i++) {
        m_textures[i].Bind(i);
    }

    glDrawElements(GL_TRIANGLES, EBO->GetCount(), GL_UNSIGNED_INT, 0);

    for (int i = m_textures.size() - 1; i >= 0; i--) {
        m_textures[i].Unbind();
    }

    EBO->Unbind();
    VAO->Unbind();
}

void Mesh::Draw(GLShader& shader) {
    VAO->Bind();
    EBO->Bind();

    for (size_t i = 0; i < m_textures.size(); i++) {
        m_textures[i].Bind(i);
    }


    glDrawElements(GL_TRIANGLES, EBO->GetCount(), GL_UNSIGNED_INT, 0);

    for (int i = m_textures.size() - 1; i >= 0; i--) {
        m_textures[i].Unbind();
    }

    EBO->Unbind();
    VAO->Unbind();
}




