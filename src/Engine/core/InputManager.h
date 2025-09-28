//
// Created by issbe on 28/09/2025.
//
#pragma once
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <map>
#include <vector>

#include "Globals.h"
#include "Window.h"
#include "GLFW/glfw3.h"


enum Key{UP, DOWN, LEFT, RIGHT, SPACE, ENTER, ESCAPE, CTRL, SHIFT, Z, Q, S, D, KeysCount};

class InputManager {
private:
    static GLFWwindow* m_window;
    static std::vector<bool> keysPressed;
    static std::map<int, Key> keyMap;
private:
    InputManager() = delete;
    ~InputManager() = delete;

public:
    static void Init(GLFWwindow* _window);

    static void getPressedKeys();
    static bool IsKeyPressed(Key key);
};



#endif //INPUTMANAGER_H
