#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Globals.h"
#include "Window.h"

#pragma once

using namespace glm;
class Camera
{
public:
    Camera(Window* window, vec3 position);
    ~Camera();

    mat4            CalculateMatrix(float nearPlane, float farPlane);
    void            Update();

private:
    Window          *m_window;
    vec3            m_position, m_initialPosition;
    vec3            m_orientation = vec3(0.0f, 0.0f, -1.0f);
    vec3            m_up = vec3(0.0f, 1.0f, 0.0f);
    vec3            m_right = vec3(1.0f, 0.0f, 0.0f);
    vec2_f          last_mousePos;

    float           m_initialSpeed = 0.01f, max_speed = 0.15, m_sensitivity = 0.1, m_fov = 45;
    bool            firstMouse = true;

    // yaw pour rota autour de l'axe des ordonnées (hor)
    // pitch pour rota autour de l'axe des abscisses (ver)
    float           yaw = -90.0f, pitch = 0.0f;

private:
    void            ProcessKeyboardInputs();
    void            ProcessMouseInputs();
    void            ProcessMouseScroll();
};
