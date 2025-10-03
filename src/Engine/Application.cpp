#include "Application.h"

#include "core/Camera.h"
#include "core/Logger.h"
#include "core/ObjectLoader.h"
#include "geometry/Triangle.h"
#include "geometry/Pyramid.h"
#include "Ogl/GLBuffer.h"
#include "Ogl/GLShader.h"
#include "geometry/Model.h"

Application::Application(Engine_window_attrs_t attrs) {
	window = new Window(attrs.wWidth, attrs.wHeight, attrs.title, attrs.iconPath);
	Init();
}

void Application::Init() {
	logger.Log(INFO, "Starting Engine...");
	InputManager::Init(window->GetWindowAdress());
	camera = new Camera(window, {0.0, 0.0, 6.0});
}

Application::~Application() {
	glfwTerminate();
}

void Application::Run() {
	Triangle t1(vec3_f(0.0f, -0.6f, -4.0f));
	Triangle t2(vec3_f(0.0f, 0.9f, -0.5f));
	Pyramid p1 (vec3_f(3.0f, 0.9f, 2.5f));

	Texture texture{"../assets/textures/wall.jpg"};
	Mesh mesh{{
		Vertex{{0.0f,  0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0, 0.0}},
		Vertex{{-0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0, 0.0}},
		Vertex{{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.5, 1.0}}
	},
		{0,1,2},
		{texture}
	};

	// GLShader shader{"../shaders/vert_camera.glsl", "../shaders/frag_camera.glsl"};
	GLShader shader{"../shaders/vert_textures.glsl", "../shaders/frag_textures.glsl"};
	texture.Bind(0);
	shader.EnableShader();
	shader.SetUniform1i("texCoord", 0);

	shader.DisableShader();
	while (!glfwWindowShouldClose(window->GetWindowAdress())) {
		InputManager::getPressedKeys();
        ProcessInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        shader.EnableShader();
		shader.SetUniformMat4("camera", camera->CalculateMatrix(0.0, -0.5));

		mesh.Draw();

        t1.Draw(shader);
        t2.Draw(shader);
		p1.Draw(shader);
        shader.DisableShader();

        glfwSwapBuffers(window->GetWindowAdress());
        glfwPollEvents();
	}

}


void Application::ProcessInput() {
	camera->ProcessKeyboardInputs();
	if (InputManager::IsKeyPressed(ESCAPE)) {
		exit(EXIT_SUCCESS);
	}
}
