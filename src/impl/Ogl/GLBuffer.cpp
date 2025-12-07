//
// Created by issbe on 23/09/2025.
//

#include "GLBuffer.h"

GLBuffer::GLBuffer(GLfloat *vertices, int countComponents, int countElement): m_countComponents(countComponents), m_countElements(countElement){
    glGenBuffers(1, &m_bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
    glBufferData(GL_ARRAY_BUFFER, countElement * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLBuffer::GLBuffer(const std::vector<Vertex> &vertices, i16 countComponents) : m_countComponents(countComponents), m_countElements(vertices.size()){
    glGenBuffers(1, &m_bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}


GLBuffer::~GLBuffer() {
    glDeleteBuffers(1, &m_bufferID);
}

void GLBuffer::Bind(){
    glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
}

void GLBuffer::Unbind(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
