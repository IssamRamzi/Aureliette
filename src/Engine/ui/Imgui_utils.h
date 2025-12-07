//
// Created by issbe on 25/10/2025.
//

#ifndef IMGUI_UTILS_H
#define IMGUI_UTILS_H


#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"


class ImguiUI {
public:
    static void Init(GLFWwindow* window);
    static void NewFrame();
};



#endif //IMGUI_UTILS_H
