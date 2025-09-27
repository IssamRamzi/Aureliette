//
// Created by issbe on 23/09/2025.
//

#ifndef GLVERTEXARRAYBUFFER_H
#define GLVERTEXARRAYBUFFER_H
#include "glad.h"
#include "GLBuffer.h"



class GLVertexArrayBuffer {
private:
    GLuint m_vertexArrayID;

public:
    GLVertexArrayBuffer();
    ~GLVertexArrayBuffer();

    void Bind() const;
    void Unbind() const;

    void AddBuffer(GLBuffer &buffer, GLint index, GLint componentCount, GLint stride, void* offset);
    // void SetIndexBuffer(IndexBuffer& buffer);

};



#endif //GLVERTEXARRAYBUFFER_H
