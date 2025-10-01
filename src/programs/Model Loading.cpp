// #include "Application.h"
//
// #include "core/Camera.h"
// #include "core/Logger.h"
// #include "core/ObjectLoader.h"
// #include "geometry/Triangle.h"
// #include "geometry/Pyramid.h"
// #include "Ogl/GLBuffer.h"
// #include "Ogl/GLShader.h"
//
// Application::Application(std::string title, int width, int height) {
// 	window = new Window(width, height, title);
// 	Init();
// }
//
// void Application::Init() {
// 	logger.Log(INFO, "Starting Engine...");
// 	InputManager::Init(window->GetWindowAdress());
// 	camera = new Camera(window, {0.0, 0.0, 6.0});
// }
//
// Application::~Application() {
// 	glfwTerminate();
// }
//
// void Application::Run() {
//
//
// 	std::vector<Vertex> triangle_verts = {
// 		Vertex{{0.0f,  0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},
// 		Vertex{{-0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},
// 		Vertex{{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}}
// 	};
//
// 	std::vector<GLuint> triangle_ind = {0,1,2};
// 	Mesh triangleMesh{triangle_verts, triangle_ind, {}};
//
//
// 	std::vector<Vertex> vertices;
// 	std::vector<GLuint> indecies;
// 	ObjectLoader::LoadObject("../objects/cat.obj", &vertices, &indecies);
// 	Mesh mesh{vertices, indecies, {}};
//
// 	Triangle t1(vec3_f(0.0f, -0.6f, -4.0f), &triangleMesh);
// 	Triangle t2(vec3_f(0.0f, 0.9f, -0.5f), &triangleMesh);
// 	Pyramid p1 (vec3_f(3.0f, 0.9f, 2.5f));
// 	GLShader shader{"../shaders/vert_camera.glsl", "../shaders/frag_camera.glsl"};
// 	while (!glfwWindowShouldClose(window->GetWindowAdress())) {
// 		InputManager::getPressedKeys();
//         ProcessInput();
//
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//         shader.EnableShader();
// 		shader.SetUniformMat4("camera", camera->CalculateMatrix(0.0, -0.5));
//
//
//         t1.Draw(shader);
//         t2.Draw(shader);
// 		p1.Draw(shader);
// 		mesh.Draw();
//         shader.DisableShader();
//
//         glfwSwapBuffers(window->GetWindowAdress());
//         glfwPollEvents();
// 	}
//
// }
//
//
// void Application::ProcessInput() {
// 	camera->ProcessKeyboardInputs();
// 	if (InputManager::IsKeyPressed(ESCAPE)) {
// 		exit(EXIT_SUCCESS);
// 	}
// }
