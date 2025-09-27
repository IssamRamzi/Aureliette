#include "Window.h"
#include "../core/Logger.h"

Window::Window(int width, int height, std::string title) : m_width(width), m_height(height), m_title(title){
    Init();
}

Window::~Window() {
	glfwDestroyWindow(m_window);
	glfwTerminate();
}


void resize_callback(GLFWwindow* window, int width, int height){
    Window* currentWindow = (Window*)glfwGetWindowUserPointer(window);
    currentWindow->SetWindowDimensions(width, height);
    glViewport(0, 0, width, height);
}


void Window::Init(){
	if(!glfwInit()){
		// Logger::Log(WARNING, "Failed to initialize GLFW\n");
		exit(EXIT_FAILURE);
	}
	// Logger::Log(INFO, "GLFW Initialization succeeded !\n");


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    

    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
    if (m_window == NULL) {
		// Logger::Log(WARNING, "Failed to create GLFW window\n");
		glfwTerminate();
        return;
	}

    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, resize_callback);
    glfwSetWindowUserPointer(m_window, this);

	if (!gladLoadGL()) {
		// Logger::Log(WARNING, "Failed to initialize GLAD\n");
		exit(EXIT_FAILURE);
	}

	// Logger::Log(WARNING, "Window Initialization succeeded\n");
}
