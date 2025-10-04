//
// Created by issbe on 28/09/2025.
//

#include "InputManager.h"

std::map<int, Key> InputManager::keyMap = {
    {GLFW_KEY_UP, UP},
    {GLFW_KEY_DOWN, DOWN},
    {GLFW_KEY_LEFT, LEFT},
    {GLFW_KEY_RIGHT, RIGHT},
    {GLFW_KEY_SPACE, SPACE},
    {GLFW_KEY_ENTER, ENTER},
    {GLFW_KEY_ESCAPE, ESCAPE},
    {GLFW_KEY_LEFT_CONTROL, CTRL},
    {GLFW_KEY_LEFT_SHIFT, SHIFT},
    {GLFW_KEY_W, Z},
    {GLFW_KEY_A, Q},
    {GLFW_KEY_S, S},
    {GLFW_KEY_D, D},
    {GLFW_KEY_E, E},
    {GLFW_KEY_Q, A},
};

std::map<int, MouseButton> InputManager::mouseMap = {
    {GLFW_MOUSE_BUTTON_LEFT, BUTTON_LEFT},
    {GLFW_MOUSE_BUTTON_RIGHT, BUTTON_RIGHT},
    {GLFW_MOUSE_BUTTON_MIDDLE, BUTTON_MIDDLE},
};

std::vector<bool> InputManager::keysPressed(KeysCount, false);
std::vector<bool> InputManager::mousePressed(MouseCount, false);

double InputManager::prevMouseX = 0.0;
double InputManager::prevMouseY = 0.0;
double InputManager::currentMouseX = 0.0;
double InputManager::currentMouseY = 0.0;

GLFWwindow* InputManager::m_window = nullptr;

void InputManager::Init(GLFWwindow* _window) {
    m_window = _window;

    if(m_window){
        glfwGetCursorPos(m_window, &currentMouseX, &currentMouseY);
        prevMouseX = currentMouseX;
        prevMouseY = currentMouseY;
    }
}

void InputManager::Update() {
    for (const std::pair<int, Key> pair : keyMap)
    {
        if (pair.second == Key::KeysCount) break;
        bool keyPressed = glfwGetKey(m_window, pair.first) == GLFW_PRESS;
        keysPressed.at(static_cast<size_t>(pair.second)) = keyPressed;
    }

    for (auto& pair : mouseMap){
        if (pair.second == MouseButton::MouseCount) break;
        bool buttonPressed = glfwGetMouseButton(m_window, pair.first) == GLFW_PRESS;
        mousePressed.at(static_cast<size_t>(pair.second)) = buttonPressed;
    }

    prevMouseX = currentMouseX;
    prevMouseY = currentMouseY;
    glfwGetCursorPos(m_window, &currentMouseX, &currentMouseY);
}

bool InputManager::IsMouseClicked(MouseButton button){
    return mousePressed.at(static_cast<size_t>(button));
}


bool InputManager::IsKeyPressed(Key key) {
    return keysPressed.at(static_cast<size_t>(key));
}

Vec2<float> InputManager::GetMovementVector(){
    float deltaX = currentMouseX - prevMouseX;
    float deltaY = currentMouseY - prevMouseY;
    return {deltaX, deltaY};
}

