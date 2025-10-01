#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.h"

#pragma once

using namespace glm;
class Camera
{
public:
    Camera(Window* window, vec3 position);
    ~Camera();

    mat4            CalculateMatrix(float nearPlane, float farPlane);
    void            ProcessKeyboardInputs();
    void            ProcessMouseInputs();
    void            ProcessMouseScroll();

private:
    Window          *m_window;
    vec3            m_position;
    vec3            m_orientation = vec3(0.0f, 0.0f, -1.0f);
    vec3            m_up = vec3(0.0f, 1.0f, 0.0f);
    vec3            m_right = vec3(1.0f, 0.0f, 0.0f);

    float           m_speed = 0.1f, m_sensitivity, m_fov = 45;
};
