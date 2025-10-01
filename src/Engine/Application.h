#include "core/Camera.h"
#include "core/Window.h"

class Application{
private:
    Window* window;
    Camera* camera;


    void ProcessInput();

public:
    Application(std::string title = "Window", int width = 800, int height = 800);
    ~Application();
    void Init();

    void Run();


};