//
// Created by issbe on 27/09/2025.
//

#ifndef GLINDEXBUFFER_H
#define GLINDEXBUFFER_H
#include "glad.h"
#include "core/Globals.h"


class GLBuffer;

class GLIndexBuffer {
private:
    GLuint m_bufferID;
    i32 m_count;

public:

    GLIndexBuffer(GLuint* data, i32 size, bool dynamic = false);
    GLIndexBuffer(GLBuffer buffer, i32 size, bool dynamic = false);

    ~GLIndexBuffer();

    void Bind() const;
    void Unbind() const;
    i32 GetCount() const {return m_count;}

};



#endif //GLINDEXBUFFER_H
