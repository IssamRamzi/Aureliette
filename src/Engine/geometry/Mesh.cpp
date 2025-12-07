//
// Created by issbe on 28/09/2025.
//

#include "Mesh.h"

#include "Ogl/GLVertexArrayBuffer.h"
#include "Ogl/GLIndexBuffer.h"
#include "Ogl/GLShader.h"
#include "../../impl/Ogl/GLTexture.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indecies, std::vector<std::shared_ptr<GLTexture>> textures)
    : m_vertices(vertices), m_indecies(indecies), m_textures(textures) {

    std::cout << "Mesh constructor: Received " << textures.size() << " textures, m_textures has " << m_textures.size() << std::endl;

    VAO = new GLVertexArrayBuffer();
    VBO = new GLBuffer(vertices, 8);
    EBO = new GLIndexBuffer(indecies);
    VAO->AddBuffer(*VBO, 0, 3, sizeof(Vertex), (void*)0);
    VAO->AddBuffer(*VBO, 1, 3, sizeof(Vertex), (void*)(offsetof(Vertex, normal)));
    VAO->AddBuffer(*VBO, 2, 2, sizeof(Vertex), (void*)(offsetof(Vertex, texcoords)));
}

Mesh::~Mesh() {
    if (VAO) delete VAO;
    if (VBO) delete VBO;
    if (EBO) delete EBO;
}

Mesh::Mesh(Mesh&& other) noexcept
    : m_vertices(std::move(other.m_vertices)),
      m_indecies(std::move(other.m_indecies)),
      m_textures(std::move(other.m_textures)),
      VAO(other.VAO),
      VBO(other.VBO),
      EBO(other.EBO) {

    other.VAO = nullptr;
    other.VBO = nullptr;
    other.EBO = nullptr;
}

Mesh& Mesh::operator=(Mesh&& other) noexcept {
    if (this != &other) {
        delete VAO;
        delete VBO;
        delete EBO;

        m_vertices = std::move(other.m_vertices);
        m_indecies = std::move(other.m_indecies);
        m_textures = std::move(other.m_textures);
        VAO = other.VAO;
        VBO = other.VBO;
        EBO = other.EBO;

        other.VAO = nullptr;
        other.VBO = nullptr;
        other.EBO = nullptr;
    }
    return *this;
}

void Mesh::Draw() {
    VAO->Bind();
    EBO->Bind();

    for (size_t i = 0; i < m_textures.size(); i++) {
        m_textures[i]->Bind(i);
    }

    glDrawElements(GL_TRIANGLES, EBO->GetCount(), GL_UNSIGNED_INT, 0);

    for (int i = m_textures.size() - 1; i >= 0; i--) {
        m_textures[i]->Unbind();
    }

    EBO->Unbind();
    VAO->Unbind();
}

void Mesh::Draw(GLShader& shader) {
    VAO->Bind();
    EBO->Bind();


    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    unsigned int normalNr = 1;
    unsigned int heightNr = 1;

    for (size_t i = 0; i < m_textures.size(); i++) {
        glActiveTexture(GL_TEXTURE0 + i);

        std::string number;
        std::string name = m_textures[i]->m_typeName;

        if (name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else if (name == "texture_specular")
            number = std::to_string(specularNr++);
        else if (name == "texture_normal")
            number = std::to_string(normalNr++);
        else if (name == "texture_height")
            number = std::to_string(heightNr++);
        else {
            std::cout << "  WARNING: Unknown texture type: " << name << std::endl;
            number = "1";
        }

        std::string uniformName = name + number;
        shader.SetUniform1i(uniformName.c_str(), i);

        // Bind the texture
        m_textures[i]->Bind(i);

        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cout << "  OpenGL Error after binding texture: " << error << std::endl;
        }
    }

    glDrawElements(GL_TRIANGLES, EBO->GetCount(), GL_UNSIGNED_INT, 0);

    // Unbind textures (optional, but good practice)
    for (int i = m_textures.size() - 1; i >= 0; i--) {
        m_textures[i]->Unbind();
    }

    EBO->Unbind();
    VAO->Unbind();
}

