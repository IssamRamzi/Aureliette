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


    void ProcessInput();

public:
    Application(Engine_window_attrs_t);
    ~Application();
    void Init();

    void Run();


};