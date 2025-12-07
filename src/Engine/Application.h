#pragma once
#include "core/Camera.h"
#include "core/Window.h"


struct Engine_window_attrs_t {
    std::string title{"Game Engine"};
    int wWidth{800};
    int wHeight{800};
    std::string iconPath{" "};
};

class Application{
private:
    Window* window;
    Camera* camera;

    bool seeLine = false;
    bool cursorDisabled = false;
    bool showCat = false;
    bool showCubes = false;
    bool showStatue = false;
    bool showBackpack = false;
    bool showSilentHill = true;
    bool imguiOpen = false; 
    // bool showTemple = true;
    float rotationSpeed = 0.05f;
	float farPlane = 100.0f;

    vec3_f clearColor = {1.0f, 0.5f, 0.31f};


    void ProcessInput();

public:
    Application(Engine_window_attrs_t&);
    ~Application();
    void Init();

    void Run();


};