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
    void            ProcessKeyboardInputs();
    void            ProcessMouseInputs();
    void            ProcessMouseScroll();

    vec3            GetPosition() const {return m_position;}
    vec3            GetUp() const {return m_up;}
    vec3            GetOrientation() const {return m_orientation;}
    vec3            GetRight() const {return m_right;}
    vec3            GetInitialPosition() const {return m_initialPosition;}
    float           GetFov() const {return m_fov;}
    float           GetSpeed() const {return m_speed;}

    void            SetFov(float fov) {m_fov = fov;}

private:
    Window          *m_window;
    vec3            m_position, m_initialPosition;
    vec3            m_orientation = vec3(0.0f, 0.0f, -1.0f);
    vec3            m_up = vec3(0.0f, 1.0f, 0.0f);
    vec3            m_right = vec3(1.0f, 0.0f, 0.0f);
    vec2_f          last_mousePos;

    float           m_initialSpeed = 0.005f, m_speed, max_speed = m_initialSpeed * 2, m_sensitivity = 0.1, m_fov = 45;
    bool            firstMouse = true;

    // yaw pour rota autour de l'axe des ordonnées (hor)
    // pitch pour rota autour de l'axe des abscisses (ver)
    float           yaw = -90.0f, pitch = 0.0f;

};
