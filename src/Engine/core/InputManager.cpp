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
};

std::vector<bool> InputManager::keysPressed(KeysCount, false);
GLFWwindow* InputManager::m_window = nullptr;

void InputManager::Init(GLFWwindow* _window) {
    m_window = _window;
}

void InputManager::getPressedKeys() {
    for (const std::pair<int, Key> pair : keyMap)
    {
        if (pair.second == Key::KeysCount) break;
        bool keyPressed = glfwGetKey(m_window, pair.first) == GLFW_PRESS;
        keysPressed.at(static_cast<size_t>(pair.second)) = keyPressed;
    }
}

bool InputManager::IsKeyPressed(Key key) {
    return keysPressed.at(static_cast<size_t>(key));
}
