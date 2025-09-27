//
// Created by issbe on 23/09/2025.
//

#include "GLVertexArrayBuffer.h"

GLVertexArrayBuffer::GLVertexArrayBuffer() {
    glGenVertexArrays(1, &m_vertexArrayID);
}

GLVertexArrayBuffer::~GLVertexArrayBuffer() {
    glDeleteVertexArrays(1, &m_vertexArrayID);
}

void GLVertexArrayBuffer::Bind() const {
    glBindVertexArray(m_vertexArrayID);
}

void GLVertexArrayBuffer::Unbind() const {
    glBindVertexArray(0);
}

void GLVertexArrayBuffer::AddBuffer(GLBuffer &buffer, GLint index, GLint componentCount, GLint stride, void* offset) {
    Bind();
    buffer.Bind();
    glVertexAttribPointer(index, componentCount, GL_FLOAT, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(index);
    buffer.Unbind();
    Unbind();
}

// void GLVertexArrayBuffer::SetIndexBuffer(IndexBuffer &buffer) {
// }
