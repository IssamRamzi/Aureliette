#include "GLTexture.h"
#include "Utils.h"
#include <iostream>
#include <algorithm>
#include "../../Engine/core/Globals.h"

GLTexture::GLTexture(const char *path, std::string typeName)
    : m_texture(0), m_width(0), m_height(0), m_numColCh(0), m_type(TEXTURE_PNG), m_typeName(typeName) {

    if (strlen(path) < 5) {
        std::cout << "Invalid texture path" << std::endl;
        return;
    }
    m_path = path;

    std::string path_str(m_path);
    i8 dot_pos = path_str.find_last_of('.');
    if (dot_pos == std::string::npos) {
        std::cout << "No file extension found" << std::endl;
        return;
    }

    std::string type = path_str.substr(dot_pos + 1);
    std::transform(type.begin(), type.end(), type.begin(), ::tolower);

    if (type == "png")
        this->m_type = TEXTURE_PNG;
    else if (type == "jpg" || type == "jpeg")
        this->m_type = TEXTURE_JPG;
    else {
        std::cout << "Unsupported texture format: " << type << std::endl;
        return;
    }

    stbi_set_flip_vertically_on_load(true);
    unsigned char* bytes = stbi_load(m_path.c_str(), &m_width, &m_height, &m_numColCh, 0);

    if (!bytes) {
        std::cout << "Failed loading the " << m_path << " texture." << std::endl;
        std::cout << "STBI Error: " << stbi_failure_reason() << std::endl;
        return;
    }

    logger.Log(INFO, "Texture loaded - Width: ", m_width, ", Height: ", m_height, ", Channels: ", m_numColCh);

    glGenTextures(1, &m_texture);
    if (m_texture == 0) {
        std::cout << "Failed to generate texture ID" << std::endl;
        stbi_image_free(bytes);
        return;
    }

    Bind(0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    GLenum format;
    switch (m_numColCh) {
        case 1:
            format = GL_RED;
            break;
        case 3:
            format = GL_RGB;
            break;
        case 4:
            format = GL_RGBA;
            break;
        default:
            std::cout << "Unsupported number of channels: " << m_numColCh << std::endl;
            glDeleteTextures(1, &m_texture);
            m_texture = 0;
            stbi_image_free(bytes);
            return;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, format, m_width, m_height, 0, format, GL_UNSIGNED_BYTE, bytes);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(bytes);
    Unbind();

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cout << "OpenGL Error during texture creation: " << error << std::endl;
    } else {
        std::cout << "Texture: " << m_path << " loaded successfully (ID: " << m_texture << ")" << std::endl;
    }
}

GLTexture::~GLTexture() {
    if (m_texture != 0) {
        glDeleteTextures(1, &m_texture);
        m_texture = 0;
    }
}

// Move constructor
GLTexture::GLTexture(GLTexture&& other) noexcept
    : m_type(other.m_type),
      m_texture(other.m_texture),
      m_path(std::move(other.m_path)),
      m_height(other.m_height),
      m_width(other.m_width),
      m_numColCh(other.m_numColCh) {

    other.m_texture = 0;
    other.m_width = 0;
    other.m_height = 0;
    other.m_numColCh = 0;
}

GLTexture& GLTexture::operator=(GLTexture&& other) noexcept {
    if (this != &other) {
        if (m_texture != 0) {
            glDeleteTextures(1, &m_texture);
        }

        m_type = other.m_type;
        m_texture = other.m_texture;
        m_path = std::move(other.m_path);
        m_height = other.m_height;
        m_width = other.m_width;
        m_numColCh = other.m_numColCh;

        other.m_texture = 0;
        other.m_width = 0;
        other.m_height = 0;
        other.m_numColCh = 0;
    }
    return *this;
}

void GLTexture::Bind(GLuint unit) const {
    if (m_texture == 0) {
        std::cout << "Warning: Trying to bind invalid texture (ID = 0)" << std::endl;
        return;
    }
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, m_texture);
}

void GLTexture::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}