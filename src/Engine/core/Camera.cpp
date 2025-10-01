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
    if (InputManager::IsKeyPressed(SHIFT)) {
        m_speed = 0.5;
    }
    else {
        m_speed = 0.1;
    }
    if(InputManager::IsKeyPressed(UP)){
        m_position += m_speed * m_orientation;
    }
    if(InputManager::IsKeyPressed(DOWN)){
        m_position += m_speed * -m_orientation;
    }
    if(InputManager::IsKeyPressed(LEFT)){
        m_position += m_speed * -m_right;
    }
    if(InputManager::IsKeyPressed(RIGHT)){
        m_position += m_speed * m_right;
    }
    // UP and Down
    if (InputManager::IsKeyPressed(Z)) {
        m_position += m_speed * m_up;
    }
    if (InputManager::IsKeyPressed(S)) {
        m_position += m_speed * -m_up;
    }
}

void Camera::ProcessMouseInputs(){

}

void Camera::ProcessMouseScroll(){
}


