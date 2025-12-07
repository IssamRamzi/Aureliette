//
// Created by issbe on 27/09/2025.
//

#ifndef GLINDEXBUFFER_H
#define GLINDEXBUFFER_H
#include <vector>

#include "../../../external/glad/include/glad/glad.h"
#include "core/Globals.h"
#include "../iBuffer.h"

class GLBuffer;

class GLIndexBuffer : iBuffer {
private:
    i32 m_count;
public:

    GLIndexBuffer(GLuint* data, i32 size, bool dynamic = false);
    GLIndexBuffer(std::vector<GLuint>, bool dynamic = false);

    ~GLIndexBuffer();

    virtual void Bind();
    virtual void Unbind();
    i32 GetCount() const {return m_count;}

};



#endif //GLINDEXBUFFER_H
