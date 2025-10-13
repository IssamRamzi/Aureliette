#include "Camera.h"
#include <iostream>

#include "InputManager.h"

Camera::Camera(Window* window, vec3 position){
    m_position = position;
    m_initialPosition = position;
    m_window = window;
    last_mousePos = InputManager::GetMousePosition();
}

Camera::~Camera(){

}

mat4 Camera::CalculateMatrix(float nearPlane, float farPlane){
    mat4 view(1.0f);
    mat4 projection(1.0f);

    view = lookAt(m_position, m_position + m_orientation, m_up);
    float asp = (float)m_window->GetWindowDimensions().x / (float)m_window->GetWindowDimensions().y;
    projection = glm::perspective(deg_to_radians(m_fov), asp, nearPlane, farPlane);

    return projection * view; // TOUJOURS PROJ * VIEW
}

void Camera::Update() {
    ProcessKeyboardInputs();
    ProcessMouseInputs();
}

void Camera::ProcessKeyboardInputs(){
    float speed;
    if (InputManager::IsKeyDown(LSHIFT)) {
        speed = max_speed;
    }
    else {
        speed = m_initialSpeed;
    }

    if (InputManager::IsKeyDown(SPACE)) {
        m_orientation = vec3(0.0f, 0.0f, -1.0f);
        m_position = m_initialPosition;
    }

    if(InputManager::IsKeyDown(Z)){
        m_position += speed * m_orientation;
    }
    if(InputManager::IsKeyDown(S)){
        m_position += speed * -m_orientation;
    }
    if(InputManager::IsKeyDown(Q)){
        m_position += speed * -m_right;
    }
    if(InputManager::IsKeyDown(D)){
        m_position += speed * m_right;
    }
    if (InputManager::IsKeyDown(A)) {
        m_position += speed * m_up;
    }
    if (InputManager::IsKeyDown(E)) {
        m_position -= speed * m_up;
    }
}

void Camera::ProcessMouseInputs(){
    vec2_f mouseDelta = InputManager::GetMouseDelta();

    mouseDelta.x *= m_sensitivity;
    mouseDelta.y *= m_sensitivity;

    yaw   += mouseDelta.x;
    pitch -= mouseDelta.y;

    if (pitch > 89.0)  pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    m_orientation.x = cos(radians(yaw)) * cos(radians(pitch));
    m_orientation.y = sin(radians(pitch));
    m_orientation.z = sin(radians(yaw)) * cos(radians(pitch));
    m_orientation = normalize(m_orientation);

    m_right = normalize(cross(m_orientation, m_up));
}



void Camera::ProcessMouseScroll(){

}


