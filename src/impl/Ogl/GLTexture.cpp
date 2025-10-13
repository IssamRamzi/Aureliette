#include "GLTexture.h"
#include "Utils.h"
#include <iostream>
#include <algorithm>
#include "../../Engine/core/Globals.h"

GLTexture::GLTexture(const char *m_path) : m_texture(0), m_width(0), m_height(0), m_numColCh(0), m_bytes(nullptr) {
    if (strlen(m_path) < 5) {
        std::cout << "Invalid texture path" << std::endl;
        return;
    }

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
    m_bytes = stbi_load(m_path, &m_width, &m_height, &m_numColCh, 0);

    if (!m_bytes) {
        std::cout << "Failed loading the " << m_path << " texture." << std::endl;
        std::cout << "STBI Error: " << stbi_failure_reason() << std::endl;
        return;
    }

    logger.Log(INFO, "Texture loaded - Width: ", m_width, ", Height: ", m_height, ", Channels: ", m_numColCh);

    glGenTextures(1, &m_texture);
    if (m_texture == 0) {
        std::cout << "Failed to generate texture ID" << std::endl;
        stbi_image_free(m_bytes);
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
            stbi_image_free(m_bytes);
            return;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, format, m_width, m_height, 0, format, GL_UNSIGNED_BYTE, m_bytes);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(m_bytes);
    m_bytes = nullptr;
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
    }
}

void GLTexture::Bind(GLuint unit) {
    if (m_texture == 0) {
        std::cout << "Warning: Trying to bind invalid texture (ID = 0)" << std::endl;
        return;
    }
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, m_texture);
}

void GLTexture::Unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}