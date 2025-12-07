//
// Created by issbe on 28/09/2025.
//

#ifndef MESH_H
#define MESH_H
#include <vector>

#include "Vertex.h"
#include "../../impl/Ogl/GLTexture.h"

class GLVertexArrayBuffer;
class GLBuffer;
class GLIndexBuffer;
class GLShader;


class Mesh {
private:
    std::vector<Vertex> m_vertices;
    std::vector<GLuint> m_indecies;

    GLVertexArrayBuffer *VAO;
    GLBuffer *VBO;
    GLIndexBuffer *EBO;

public:
    std::vector<std::shared_ptr<GLTexture>> m_textures;

    Mesh(std::vector<Vertex> vertices,
         std::vector<GLuint> indices,
         std::vector<std::shared_ptr<GLTexture>> textures);
    ~Mesh();

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    // Add move operations
    Mesh(Mesh&& other) noexcept;
    Mesh& operator=(Mesh&& other) noexcept;

    void Draw();
    void Draw(GLShader& shader);
};



#endif //MESH_H
