//
// Created by issbe on 23/09/2025.
//

#ifndef GLBUFFER_H
#define GLBUFFER_H
#include "glad.h"
#include "Vertex.h"
#include "core/Globals.h"


class GLBuffer {
private:
    GLuint m_bufferID;
    i32 m_countElements, m_countComponents;
public:
    GLBuffer(GLfloat* vertices, int countComponents, int countElements);
    GLBuffer(const std::vector<Vertex> &vertices, i16 countComponents);
    ~GLBuffer();

    void Bind() const;
    void Unbind() const;
    i32 GetCountComponents() const{return m_countComponents;}
    i32 GetCountElements() const{return m_countElements;}

};



#endif //GLBUFFER_H
