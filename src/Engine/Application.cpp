#include "Application.h"

#include "core/Camera.h"
#include "core/Logger.h"
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
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
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

	std::vector<Vertex> cubeVertices = {
		Vertex{{-1.0,-1.0,-1.0}, {0.0,0.0,0.0}},
		Vertex{{+1.0,-1.0,-1.0}, {1.0,0.0,0.0}},
		Vertex{{+1.0,+1.0,-1.0}, {1.0,1.0,0.0}},
		Vertex{{-1.0,+1.0,-1.0}, {0.0,1.0,0.0}},
		Vertex{{-1.0,-1.0,+1.0}, {0.0,0.0,1.0}},
		Vertex{{+1.0,-1.0,+1.0}, {1.0,0.0,1.0}},
		Vertex{{+1.0,+1.0,+1.0}, {1.0,1.0,1.0}},
		Vertex{{-1.0,+1.0,+1.0}, {0.0,1.0,1.0}}
	};
	std::vector<GLuint> cubeIndecies = {
		0, 1, 2,  0, 2, 3,
		// back
		4, 5, 6,  4, 6, 7,
		// left
		0, 4, 7,  0, 7, 3,
		// right
		1, 5, 6,  1, 6, 2,
		// top
		3, 2, 6,  3, 6, 7,
		// bottom
		0, 1, 5,  0, 5, 4
	};
	Mesh cubeMesh{cubeVertices, cubeIndecies, {}};

	Mesh mesh{{
		Vertex{{0.0f,  0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0, 0.0}},
		Vertex{{-0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0, 0.0}},
		Vertex{{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.5, 1.0}}
	},
		{0,1,2},
		{}
	};



	GLShader shader{"../shaders/vert_camera.glsl", "../shaders/frag_camera.glsl"};
	shader.EnableShader();
	shader.SetUniform1i("texCoord", 0);

	shader.DisableShader();
	while (!glfwWindowShouldClose(window->GetWindowAdress())) {
		InputManager::Update();
        ProcessInput();
		glEnable(GL_DEPTH_TEST);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        shader.EnableShader();
		shader.SetUniformMat4("camera", camera->CalculateMatrix(0.1, 100.f));


		// mesh.Draw();

		cubeMesh.Draw();
        t1.Draw(shader);
        // t2.Draw(shader);
		// p1.Draw(shader);
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

	if (InputManager::IsKeyPressed(ENTER)) {
		glPolygonMode(GL_FRONT_AND_BACK, seeLine ? GL_FILL : GL_LINE);
		seeLine = !seeLine;
	}
}
