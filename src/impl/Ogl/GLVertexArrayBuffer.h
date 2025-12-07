//
// Created by issbe on 23/09/2025.
//

#ifndef GLVERTEXARRAYBUFFER_H
#define GLVERTEXARRAYBUFFER_H
#include "../../../external/glad/include/glad/glad.h"
#include "GLBuffer.h"
#include "../iBuffer.h"




class GLVertexArrayBuffer : iBuffer {
private:
    GLuint m_bufferID;
public:
    GLVertexArrayBuffer();
    ~GLVertexArrayBuffer();

    virtual void Bind();
    virtual void Unbind();

    void AddBuffer(GLBuffer &buffer, GLint index, GLint componentCount, GLint stride, void* offset);

};



#endif //GLVERTEXARRAYBUFFER_H
