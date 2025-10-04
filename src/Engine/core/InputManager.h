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


enum Key{UP, DOWN, LEFT, RIGHT, SPACE, ENTER, ESCAPE, CTRL, SHIFT, Z, Q, S, D, A, E, KeysCount};
enum MouseButton{BUTTON_LEFT, BUTTON_RIGHT, BUTTON_MIDDLE, MouseCount};

class InputManager {
private:
    static GLFWwindow* m_window;
    static std::vector<bool> keysPressed;
    static std::vector<bool> mousePressed;
    static std::map<int, Key> keyMap;
    static std::map<int, MouseButton> mouseMap;

    static double prevMouseX, currentMouseX, prevMouseY, currentMouseY;

private:
    InputManager() = delete;
    ~InputManager() = delete;

public:
    static void Init(GLFWwindow* _window);

    static void Update();

    static bool IsKeyPressed(Key key);
    static bool IsMouseClicked(MouseButton button);

    static Vec2<float> GetMovementVector();
};



#endif //INPUTMANAGER_H
