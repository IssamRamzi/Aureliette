//
// Created by issbe on 28/09/2025.
//

#ifndef MESH_H
#define MESH_H
#include <vector>

#include "Vertex.h"


class GLVertexArrayBuffer;
class GLBuffer;
class GLIndexBuffer;
class GLShader;

class Mesh {
private:
    std::vector<Vertex> m_vertices;
    std::vector<GLuint> m_indecies;

    GLBuffer *VBO;
    GLIndexBuffer *EBO;
    GLVertexArrayBuffer *VAO;
public:
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indecies);
    ~Mesh();
    void Draw();
};



#endif //MESH_H
