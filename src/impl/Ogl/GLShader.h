#ifndef SHADER_H
#define SHADER_H


#include <glad/glad.h>

#include "glm/glm.hpp"
#include "math/kMath.h"


class GLShader {
private:
    GLuint      m_shaderProgram;
    const char  *m_vertexPath, *m_fragmentPath;

public:
    GLShader(const char* vertexPath, const char* fragmentPath);
    ~GLShader();

    GLShader(const GLShader&) = delete;
    GLShader& operator=(const GLShader&) = delete;

    GLShader(GLShader&& other) noexcept :
        m_shaderProgram(other.m_shaderProgram),
        m_vertexPath(other.m_vertexPath),
        m_fragmentPath(other.m_fragmentPath) {
        other.m_shaderProgram = 0;
    }

    GLShader& operator=(GLShader&& other) noexcept {
        if (this != &other) {
            if (m_shaderProgram != 0) {
                glDeleteProgram(m_shaderProgram);
            }

            m_shaderProgram = other.m_shaderProgram;
            m_vertexPath = other.m_vertexPath;
            m_fragmentPath = other.m_fragmentPath;

            other.m_shaderProgram = 0;
        }
        return *this;
    }

    void        EnableShader();
    void        DisableShader();
    GLuint      GetShaderID() const;
    GLint       GetUniformLoc(const GLchar *name) const;


    void        SetUniform1f(const GLchar* name, float val);
    void        SetUniform2f(const GLchar* name, Vec2<float> vec);
    void        SetUniform3f(const GLchar* name, Vec3<float> vec);
    void        SetUniform4f(const GLchar* name, Vec4<float> vec);
    void        SetUniform1i(const GLchar* name, int val);
    void        SetUniform2i(const GLchar* name, Vec2<int> vec);
    void        SetUniform3i(const GLchar* name, Vec3<int> vec);
    void        SetUniform4i(const GLchar* name, Vec4<int> vec);

    void        SetUniformMat4(const GLchar *name, Matrix4<float> mat);
    void        SetUniformMat4(const GLchar *name, glm::mat4 mat);
};

#endif //SHADER_H
