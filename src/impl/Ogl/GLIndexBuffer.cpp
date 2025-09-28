//
// Created by issbe on 27/09/2025.
//

#include "GLIndexBuffer.h"
#include "GLBuffer.h"

GLIndexBuffer::GLIndexBuffer(GLuint *data, i32 count, bool dynamic) : m_count(count) {
    if (data == nullptr) return;
    glGenBuffers(1, &m_bufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,count * sizeof(GLuint), data, dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
}

GLIndexBuffer::GLIndexBuffer(std::vector<GLuint> data, bool dynamic) : m_count(data.size()){
    if (data.empty()) return;
    glGenBuffers(1, &m_bufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,m_count * sizeof(GLuint), data.data(), dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);

}

GLIndexBuffer::~GLIndexBuffer() {
    glDeleteBuffers(1, &m_bufferID);
}

void GLIndexBuffer::Bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
}

void GLIndexBuffer::Unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
