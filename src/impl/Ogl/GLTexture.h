//
// Created by issbe on 09/06/2025.
//

#ifndef TEXTURE_H
#define TEXTURE_H

#include "stb_image/stb_image.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>


enum TextureType {
    TEXTURE_PNG,
    TEXTURE_JPG
};


class GLTexture {
public:
    GLTexture(const char* m_path);
    ~GLTexture();

    TextureType     m_type;
    GLuint          m_texture;
private:
    char*           m_path;
    unsigned char*  m_bytes;
    int             m_height, m_width, m_numColCh;

public:
    void            Bind(GLuint unit = 0);
    void            Unbind();

};



#endif //TEXTURE_H
