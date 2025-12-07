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
#include "math/kMath.h"


enum Key{
        UP, DOWN, LEFT, RIGHT, SPACE, ENTER, ESCAPE, LCTRL, RCTRL, LSHIFT, RSHIFT, TAB,
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y , Z, KeysCount};
enum MouseButton{BUTTON_LEFT, BUTTON_RIGHT, BUTTON_MIDDLE, MouseCount};

class InputManager {
private:
    static GLFWwindow* m_window;
    static std::vector<bool> keysPressed;
    static std::vector<bool> lastKeysPressed;
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

    static bool IsKeyDown(Key key);
    static bool IsKeyPressed(Key key);
    static bool IsMouseClicked(MouseButton button);

    static Vec2<float> GetMousePosition();
    static Vec2<float> GetMouseDelta();
};



#endif //INPUTMANAGER_H
