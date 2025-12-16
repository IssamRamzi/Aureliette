#pragma once
#include "core/Camera.h"
#include "core/Window.h"
#include "core/Renderer.hpp"
#include "event/Time.h"

#include <memory>

struct Engine_window_attrs_t {
    std::string title{"Game Engine"};
    int wWidth{800};
    int wHeight{800};
    std::string iconPath{" "};
};

class Application{
private:
    std::unique_ptr<Window> window;
    std::unique_ptr<Camera> camera;
    std::unique_ptr<Renderer> renderer;


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
	float farPlane = 150.0f;
	float speed = 5.0f;
	float fov = 90.0f;
	float angle = 0.0f;

	vec3_f scale = {1.0, 1.0, 1.0};
	vec3_f rotation = {0.0, 0.0, 0.0};

    vec3_f clearColor = {1.0f, 0.5f, 0.31f};


    void ProcessInput();
    void ProcessGui();


public:
    Application(Engine_window_attrs_t&);
    ~Application();
    void Init();

    void Run();


};