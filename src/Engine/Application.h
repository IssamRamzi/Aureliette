#include "window/Window.h"

class Application{
private:
    Window* window;

public:
    Application(std::string title, int width, int height);
    void Init();

    void Run();


};