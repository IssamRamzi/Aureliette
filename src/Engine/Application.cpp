#include "Application.h"

#include "core/Camera.h"
#include "core/Logger.h"
#include "geometry/Triangle.h"
#include "geometry/Pyramid.h"
#include "Ogl/GLBuffer.h"
#include "Ogl/GLShader.h"
#include "geometry/Model.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

Application::Application(Engine_window_attrs_t& attrs) {
	window = new Window(attrs.wWidth, attrs.wHeight, attrs.title, attrs.iconPath);
	InputManager::Init(window->GetWindowAdress());
	camera = new Camera(window, {0.0, 0.0, 6.0});

	Init();
}

void Application::Init() {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	// Optional: enable keyboard/gamepad navigation
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

	// Setup style
	ImGui::StyleColorsDark(); // or ImGui::StyleColorsClassic();

	// Setup platform/renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window->GetWindowAdress(), true);
	ImGui_ImplOpenGL3_Init("#version 330"); // OpenGL version used
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	logger.Log(INFO, "Starting Engine...");
}

Application::~Application() {
	glfwTerminate();
}

void Application::Run() {
	Triangle t1(vec3_f(0.0f, -0.6f, -4.0f));
	Triangle t2(vec3_f(0.0f, 0.9f, -0.5f));
	Pyramid p1 (vec3_f(3.0f, 0.9f, 2.5f));

	std::vector<Vertex> cubeVertices = {
		Vertex{{-1.0,-1.0,-1.0}, {0.0,0.0,0.0}, {0.0f, 0.0f}},
		Vertex{{+1.0,-1.0,-1.0}, {1.0,0.0,0.0}, {1.0f, 0.0f}},
		Vertex{{+1.0,+1.0,-1.0}, {1.0,1.0,0.0}, {1.0f, 1.0f}},
		Vertex{{-1.0,+1.0,-1.0}, {0.0,1.0,0.0}, {0.0f, 1.0f}},
		Vertex{{-1.0,-1.0,+1.0}, {0.0,0.0,1.0}, {0.0f, 0.0f}},
		Vertex{{+1.0,-1.0,+1.0}, {1.0,0.0,1.0}, {1.0f, 0.0f}},
		Vertex{{+1.0,+1.0,+1.0}, {1.0,1.0,1.0}, {1.0f, 1.0f}},
		Vertex{{-1.0,+1.0,+1.0}, {0.0,1.0,1.0}, {0.0f, 1.0f}}
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

	std::vector<vec3_f> cubesPositions = {
		{ 12.0f,  3.0f, -14.0f},
		{-13.0f,  5.0f,  11.0f},
		{  0.0f,  2.0f,   0.0f},
		{ 14.0f, -4.0f,   9.0f},
		{-10.0f,  6.0f, -12.0f},
		{  8.0f,  1.0f,  14.0f},
		{-12.0f, -3.0f,  -8.0f},
		{ 15.0f,  0.0f,   5.0f},
		{-14.0f,  2.0f, -10.0f},
		{  0.0f,  7.0f,  15.0f}
	};
	std::cout << cubesPositions.size() << std::endl;
	std::vector<float> cubesSize(10, 0.5f);

	std::vector<vec3_f> cubesRotation = {
		{1.0,0.0,0.0},
		{1.0,0.0,0.0},
		{1.0,1.0,0.0},
		{1.0,0.0,0.0},
		{1.0,0.0,0.0},
		{1.0,1.0,0.0},
		{1.0,0.0,0.0},
		{1.0,0.0,0.0},
		{1.0,0.0,0.0},
		{1.0,0.0,0.0},

	};

	Mesh mesh{{
		Vertex{{0.0f,  0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0, 0.0}},
		Vertex{{-0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0, 0.0}},
		Vertex{{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.5, 1.0}}
	},
		{0,1,2},
		{}
	};


	GLShader shader{"../assets/shaders/vert_textures.glsl", "../assets/shaders/frag_textures.glsl"};
	Texture wall{"../assets/textures/wall.jpg"};
	Texture face{"../assets/textures/awesomeface.png"};
	shader.EnableShader();

	shader.DisableShader();
	float angle = 0;
	while (!glfwWindowShouldClose(window->GetWindowAdress())) {
		InputManager::Update();
        ProcessInput();
		glEnable(GL_DEPTH_TEST);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();


		ImGui::Begin("Camera Info");
		ImGui::Text("Position: %.2f, %.2f, %.2f", camera->GetPosition().x, camera->GetPosition().y, camera->GetPosition().z);
		ImGui::End();


        shader.EnableShader();
		shader.SetUniformMat4("camera", camera->CalculateMatrix(0.1, 100.f));

		for (int i =0; i < cubesPositions.size(); i++) {
			vec3_f scale {cubesSize[i], cubesSize[i], cubesSize[i]};
			vec3_f rotation = vec3_f::normalize(cubesRotation[i]);
			mat4_f modelMatrix = mat4_f::translation(cubesPositions[i]) * mat4_f::rotation(angle, rotation) * mat4_f::scale(scale);

			shader.SetUniformMat4("model", modelMatrix);
			wall.Bind();
			cubeMesh.Draw();
		}
		angle += 0.05f;

		wall.Unbind();
        shader.DisableShader();


		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


        glfwSwapBuffers(window->GetWindowAdress());
        glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

}


void Application::ProcessInput() {
	if (!cursorDisabled)
	camera->Update();
	if (InputManager::IsKeyPressed(ESCAPE)) {
		exit(EXIT_SUCCESS);
	}

	if (InputManager::IsKeyPressed(CTRL)) {
		std::cout << "CTRL Pressed" << std::endl;
		glfwSetInputMode(window->GetWindowAdress(), GLFW_CURSOR, cursorDisabled ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
		cursorDisabled = !cursorDisabled;
	}

	if (InputManager::IsKeyPressed(ENTER)) {
		glPolygonMode(GL_FRONT_AND_BACK, seeLine ? GL_FILL : GL_LINE);
		seeLine = !seeLine;
	}
}
