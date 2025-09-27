#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include "../math/kMath.h"


class Window{
private:
    GLFWwindow* m_window;
    bool m_windowShouldClose;
    int m_width, m_height;
    std::string m_title;

private:
    void Init();

    friend void resize_callback(GLFWwindow* window, int width, int height);
    
    
public:
    Window(int width, int height, std::string title);
    ~Window();


    inline GLFWwindow* GetWindowAdress(){return m_window;}
    inline Vec2<int> GetWindowDimensions(){return Vec2<int>{m_width, m_height};}
    inline void SetWindowDimensions(int width, int height){m_width = width, m_height = height;}


};