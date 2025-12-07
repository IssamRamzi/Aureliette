#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <memory>
#include "stb_image/stb_image.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>

enum TextureType {
    TEXTURE_PNG,
    TEXTURE_JPG
};

class GLTexture {
public:
    GLTexture(const char* path, std::string typeName = "texture_diffuse");
    ~GLTexture();

    GLTexture(const GLTexture&) = delete;
    GLTexture& operator=(const GLTexture&) = delete;

    GLTexture(GLTexture&& other) noexcept;
    GLTexture& operator=(GLTexture&& other) noexcept;

    TextureType     m_type;
    GLuint          m_texture;
    std::string     m_typeName;

private:
    std::string     m_path;
    int             m_height, m_width, m_numColCh;

public:
    void            Bind(GLuint unit = 0) const;
    void            Unbind() const;
    std::string     GetPath() const { return m_path; }
    bool            IsValid() const { return m_texture != 0; }
};

#endif //TEXTURE_H