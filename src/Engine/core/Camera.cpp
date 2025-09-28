#include "Camera.h"
#include <iostream>

#include "InputManager.h"

Camera::Camera(Window* window, vec3 position){
    m_position = position;
    m_window = window;
}

Camera::~Camera(){

}

mat4 Camera::CalculateMatrix(float nearPlane, float farPlane){
    mat4 view(1.0f);
    mat4 projection(1.0f);

    view = lookAt(m_position, m_position + m_orientation, m_up);
    projection = glm::perspective(m_fov, (float)m_window->GetWindowDimensions().x / (float)m_window->GetWindowDimensions().y, nearPlane, farPlane);

    return projection * view; // TOUJOURS PROJ * VIEW (3h de perdu a cause de ca)
}

void Camera::ProcessKeyboardInputs(){
    if(InputManager::IsKeyPressed(UP)){
        m_position += m_speed * m_orientation;
    }
    if(InputManager::IsKeyPressed(DOWN)){
        m_position += m_speed * -m_orientation;
    }
}

void Camera::ProcessMouseInputs(){

}

void Camera::ProcessMouseScroll(){
}


