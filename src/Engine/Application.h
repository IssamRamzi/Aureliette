#include "core/Window.h"

class Application{
private:
    Window* window;

public:
    Application(std::string title = "Window", int width = 800, int height = 800);
    void Init();

    void Run();


};