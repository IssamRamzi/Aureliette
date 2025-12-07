//
// Created by issbe on 23/09/2025.
//

#include "GLVertexArrayBuffer.h"

GLVertexArrayBuffer::GLVertexArrayBuffer() {
    glGenVertexArrays(1, &m_bufferID);
}

GLVertexArrayBuffer::~GLVertexArrayBuffer() {
    glDeleteVertexArrays(1, &m_bufferID);
}

void GLVertexArrayBuffer::Bind() {
    glBindVertexArray(m_bufferID);
}

void GLVertexArrayBuffer::Unbind() {
    glBindVertexArray(0);
}

void GLVertexArrayBuffer::AddBuffer(GLBuffer &buffer, GLint index, GLint componentCount, GLint stride, void* offset) {
    Bind();
    buffer.Bind();
    glVertexAttribPointer(index, componentCount, GL_FLOAT, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(index);
    // buffer.Unbind();
    Unbind();
}

// void GLVertexArrayBuffer::SetIndexBuffer(IndexBuffer &buffer) {
// }
