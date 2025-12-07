#include "Window.h"
#include "Logger.h"
#include "core/Globals.h"
#include "stb_image/stb_image.h"

Window::Window(int width, int height, std::string title, std::string iconpath) : m_width(width), m_height(height), m_title(title), m_iconPath(iconpath){
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
		logger.Log(WARNING, "Failed to initialize GLFW");
		exit(EXIT_FAILURE);
	}
	logger.Log(INFO, "GLFW Initialization succeeded !");


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_DEPTH_BITS, 24);

    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
    if (m_window == NULL) {
		logger.Log(WARNING, "Failed to create GLFW window\n");
		glfwTerminate();
        return;
	}

	if (!m_iconPath.empty()) {
		GLFWimage images[1];
		images[0].pixels = stbi_load(m_iconPath.c_str(), &images[0].width, &images[0].height, 0, 4); //rgba channels
		glfwSetWindowIcon(m_window, 1, images);
		stbi_image_free(images[0].pixels);
	}

    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, resize_callback);
    glfwSetWindowUserPointer(m_window, this);

	if (!gladLoadGL()) {
		logger.Log(WARNING, "Failed to initialize GLAD");
		exit(EXIT_FAILURE);
	}
	glfwGetWindowPos(m_window, &position.x, &position.y);
	logger.Log(DEBUG, "Window Creation succeeded !");
}

