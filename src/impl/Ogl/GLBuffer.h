//
// Created by issbe on 23/09/2025.
//

#ifndef GLBUFFER_H
#define GLBUFFER_H
#include "../../../external/glad/include/glad/glad.h"
#include "../../Engine/geometry/Vertex.h"
#include "core/Globals.h"
#include "../iBuffer.h"


class GLBuffer : iBuffer {
private:
    i32 m_countElements, m_countComponents;
public:
    GLBuffer(GLfloat* vertices, int countComponents, int countElements);
    GLBuffer(const std::vector<Vertex> &vertices, i16 countComponents);
    ~GLBuffer();

    virtual void Bind();
    virtual void Unbind();
    i32 GetCountComponents() const{return m_countComponents;}
    i32 GetCountElements() const{return m_countElements;}

};



#endif //GLBUFFER_H
