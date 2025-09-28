// #include "Application.h"
//
// #include "core/Logger.h"
// #include "Ogl/GLBuffer.h"
// #include "Ogl/GLIndexBuffer.h"
// #include "Ogl/GLShader.h"
// #include "Ogl/GLVertexArrayBuffer.h"
//
// void processInput();
//
// Application::Application(std::string title, int width, int height) {
// 	window = new Window(width, height, title);
// 	Init();
// }
//
// void Application::Init() {
// 	logger.Log(INFO, "Starting Engine...");
// 	InputManager::Init(window->GetWindowAdress());
// }
//
// void Application::Run() {
// 	std::vector<Vertex> vertices = {
// 		// positions										   // colors
// 		Vertex{{-0.5f,  0.5f, 0.0f}, {1.0f, 0.0f, 0.5f}},
// 		Vertex{{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 1.0f}},
// 		Vertex{{0.5f, -0.5f, 0.0f}, {0.0f, 0.3f, 1.0f}},
// 		Vertex{{0.5f,  0.5f, 0.0f}, {1.0f, 1.0f, 0.0f}},
//
// 	};
//
// 	std::vector<GLuint> indices = {
// 		0, 1, 2,
// 		2, 3, 0
// 	};
//
// 	GLVertexArrayBuffer VAO{};
// 	GLBuffer VBO{vertices, 6};
// 	GLIndexBuffer EBO{indices};
//
// 	VAO.AddBuffer(VBO, 0, 3, 6 * sizeof(float), (void*)0);
// 	VAO.AddBuffer(VBO, 1, 3, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//
// 	GLShader shader{"../shaders/vert_transform.glsl", "../shaders/frag_transform.glsl"};
// 	shader.EnableShader();
// 	mat4_f transform{1.0};
// 	float i = 0.1;
// 	float s = 0.3;
// 	int bs = -1;
// 	shader.DisableShader();
//
// 	while (!glfwWindowShouldClose(window->GetWindowAdress())) {
// 		InputManager::getPressedKeys();
//
// 		processInput();
//
// 		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
// 		glClear(GL_COLOR_BUFFER_BIT);
//     	vec3_f scale{s,s,s};
// 		transform = mat4_f::scale(scale) * mat4_f::rotation(i, {0.0, 0.0, 1.0});
// 		shader.EnableShader();
// 		shader.SetUniformMat4("transform", transform);
//
//
//
// 		VAO.Bind();
// 		EBO.Bind();
//
// 		glDrawElements(GL_TRIANGLES, EBO.GetCount(), GL_UNSIGNED_INT, 0);
//
// 		EBO.Unbind();
// 		VAO.Unbind();
// 		shader.DisableShader();
//
// 		glfwSwapBuffers(window->GetWindowAdress());
// 		glfwPollEvents();
// 		i +=0.1;
//
// 		if (s > 0.8 || s < 0.2)
// 			bs *= -1;
// 		s+=0.0005 * bs;
//
//
// 	}
//
// 	glfwTerminate();
// }
//
//
// void processInput() {
// 	if (InputManager::IsKeyPressed(ESCAPE)) {
// 		exit(EXIT_SUCCESS);
// 	}
// }
