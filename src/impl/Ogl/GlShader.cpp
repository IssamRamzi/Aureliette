#include "GLShader.h"
#include "Utils.h"
#include "core/Globals.h"
#include "glm/fwd.hpp"
#include "glm/gtc/type_ptr.hpp"

GLShader::GLShader(const char *vertexPath, const char *fragmentPath) : m_vertexPath(vertexPath), m_fragmentPath(fragmentPath){
    logger.Log(INFO, "Loading Vertex Shader from ", vertexPath);
    std::string vertex = GetTextFromFile(vertexPath);
    logger.Log(INFO, "Loading Fragment Shader from ", fragmentPath);
    std::string fragment = GetTextFromFile(fragmentPath);

    if (vertex.empty() || fragment.empty()) {
        logger.Log(INFO, "Failed loading the shaders.");
        return;
    }

    const char* v_char = vertex.c_str();
    const char* f_char = fragment.c_str();

    GLuint vertex_p, fragment_p;
    vertex_p = glCreateShader(GL_VERTEX_SHADER);
    fragment_p = glCreateShader(GL_FRAGMENT_SHADER);

    if (vertex_p == 0 || fragment_p == 0) {
        logger.Log(WARNING, "Failed creating the shaders.");
        return;
    }

    glShaderSource(vertex_p, 1, &v_char, NULL);
    glCompileShader(vertex_p);


    GLint success = 0;
    glGetShaderiv(vertex_p, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        GLint length = 0;
        glGetShaderiv(vertex_p, GL_INFO_LOG_LENGTH, &length);
        if (length > 0) {
            char* infoLog = new char[length];
            glGetShaderInfoLog(vertex_p, length, &length, infoLog);
            logger.Log(WARNING, "VERTEX SHADER COMPILATION ERROR:", infoLog);
            delete[] infoLog;
        }
        glDeleteShader(vertex_p);
        glDeleteShader(fragment_p);
        return;
    }

    glShaderSource(fragment_p, 1, &f_char, NULL);
    glCompileShader(fragment_p);
    glGetShaderiv(fragment_p, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        GLint length = 0;
        glGetShaderiv(fragment_p, GL_INFO_LOG_LENGTH, &length);
        if (length > 0) {
            char* infoLog = new char[length];
            glGetShaderInfoLog(fragment_p, length, &length, infoLog);
            logger.Log(WARNING, "FRAGMENT SHADER COMPILATION ERROR:", infoLog);
            delete[] infoLog;
        }
        glDeleteShader(vertex_p);
        glDeleteShader(fragment_p);
        return;
    }

    GLuint program = glCreateProgram();
    if (program == 0) {
        logger.Log(WARNING, "Failed to create shader program");
        glDeleteShader(vertex_p);
        glDeleteShader(fragment_p);
        return;
    }

    glAttachShader(program, vertex_p);
    glAttachShader(program, fragment_p);
    glLinkProgram(program);

    glDeleteShader(vertex_p);
    glDeleteShader(fragment_p);

    glValidateProgram(program);
    m_shaderProgram = program;
    logger.Log(DEBUG, "Shader created successfully.");
}

GLShader::~GLShader() {
    glDeleteProgram(m_shaderProgram);
}

void GLShader::EnableShader() {
    glUseProgram(m_shaderProgram);
}

void GLShader::DisableShader() {
    glUseProgram(0);
}

GLuint GLShader::GetShaderID() const{
    return m_shaderProgram;
}

GLint GLShader::GetUniformLoc(const GLchar *name) const {
    return glGetUniformLocation(m_shaderProgram, name);
}

void GLShader::SetUniform1f(const GLchar *name, float val) {
    GLint location = GetUniformLoc(name);
    glUniform1f(location, val);
}

void GLShader::SetUniform2f(const GLchar *name, Vec2<float> vec) {
    GLint location = GetUniformLoc(name);
    glUniform2f(location, vec.x, vec.y);
}

void GLShader::SetUniform3f(const GLchar *name, Vec3<float> vec) {
    GLint location = GetUniformLoc(name);
    glUniform3f(location, vec.x, vec.y, vec.z);
}

void GLShader::SetUniform4f(const GLchar *name, Vec4<float> vec) {
    GLint location = GetUniformLoc(name);
    glUniform4f(location, vec.x, vec.y, vec.z, vec.w);
}

void GLShader::SetUniform1i(const GLchar *name, int val) {
    GLint location = GetUniformLoc(name);
    glUniform1i(location, val);
}

void GLShader::SetUniform2i(const GLchar *name, Vec2<int> vec) {
    GLint location = GetUniformLoc(name);
    glUniform2i(location, vec.x, vec.y);
}

void GLShader::SetUniform3i(const GLchar *name, Vec3<int> vec) {
    GLint location = GetUniformLoc(name);
    glUniform3i(location, vec.x, vec.y, vec.z);
}

void GLShader::SetUniform4i(const GLchar *name, Vec4<int> vec) {
    GLint location = GetUniformLoc(name);
    glUniform4i(location, vec.x, vec.y, vec.z, vec.w);
}

void GLShader::SetUniformMat4(const GLchar *name, Matrix4<float> mat) {
    GLint location = GetUniformLoc(name);
    glUniformMatrix4fv(location, 1, GL_FALSE, mat.data);
}
void GLShader::SetUniformMat4(const GLchar *name, glm::mat4 mat) {
    GLint location = GetUniformLoc(name);
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}