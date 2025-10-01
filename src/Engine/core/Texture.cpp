//
// Created by issbe on 09/06/2025.
//

#include "Texture.h"
#include "Utils.h"
#include <iostream>

Texture::Texture(const char *m_path) {
    std::string type = std::string(m_path).substr(std::string(m_path).length() - 3, std::string(m_path).length()).c_str();

    if (type == "png")
        this->m_type = TEXTURE_PNG;
    else if (type == "jpg")
        this->m_type = TEXTURE_JPG;
    else {
        std::cout << "Unsupported texture format: " << type << std::endl;
        return;
    }

    stbi_set_flip_vertically_on_load(true);
    m_bytes = stbi_load(m_path, &m_width, &m_height, &m_numColCh, 0);

    if (m_bytes) {
        std::cout << "Texture loaded - Width: " << m_width << ", Height: " << m_height << ", Channels: " << m_numColCh << std::endl;

        glGenTextures(1, &m_texture);
        std::cout << "Generated texture ID: " << m_texture << std::endl;

        Bind(0); 

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        if (this->m_type == TEXTURE_JPG) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_bytes);
            std::cout << "Uploaded JPG texture to GPU" << std::endl;
        } else if (this->m_type == TEXTURE_PNG) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_bytes);
            std::cout << "Uploaded PNG texture to GPU" << std::endl;
        }

        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(m_bytes);
        Unbind();

        
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cout << "OpenGL Error during texture creation: " << error << std::endl;
        } else {
            std::cout << "Texture: " << m_path << ", loaded successfully." << std::endl;
        }
    }
    else {
        std::cout << "Failed loading the " << m_path << " texture." << std::endl;
        std::cout << "STBI Error: " << stbi_failure_reason() << std::endl;
    }
}

Texture::~Texture() {
    glDeleteTextures(1, &m_texture);
}

void Texture::Bind(GLuint unit) {
    if (m_texture == 0) {
        std::cout << "Warning: Trying to bind invalid texture (ID = 0)" << std::endl;
        return;
    }

    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    GLint boundTexture;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &boundTexture);
    if (boundTexture != (GLint)m_texture) {
        std::cout << "Error: Texture binding failed. Expected: " << m_texture << ", Got: " << boundTexture << std::endl;
    } else if (unit == 0) { 
        std::cout << "Texture " << m_texture << " successfully bound to unit " << unit << std::endl;
    }
}

void Texture::Unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}