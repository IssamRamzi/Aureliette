// #include "Application.h"
//
// #include "core/Logger.h"
// #include "Ogl/GLBuffer.h"
// #include "Ogl/GLIndexBuffer.h"
// #include "Ogl/GLShader.h"
// #include "Ogl/GLVertexArrayBuffer.h"
//
// Application::Application(std::string title, int width, int height) {
// 	// Logger::Init("logs.txt");
// 	Init();
// 	window = new Window(width, height, title);
// }
//
// void Application::Init() {
// }
//
// void Application::Run() {
// 	GLfloat vertices[] = {
// 		// positions        // colors
// 		0.0f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,
// 	   -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 1.0f,
// 		0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f
//    };
//
// 	GLuint indices[] = {
// 		0, 1, 2
// 	};
//
// 	GLVertexArrayBuffer VAO{};
// 	GLBuffer VBO{vertices, 18, sizeof(vertices)};
// 	GLIndexBuffer EBO{indices, 3};
//
// 	VAO.AddBuffer(VBO, 0, 3, 6 * sizeof(float), (void*)0);
// 	VAO.AddBuffer(VBO, 1, 3, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//
// 	GLShader shader{"../shaders/vert_rgb.glsl", "../shaders/frag_rgb.glsl"};
//
// 	while (!glfwWindowShouldClose(window->GetWindowAdress())) {
// 		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
// 		glClear(GL_COLOR_BUFFER_BIT);
//
// 		shader.EnableShader();
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
// 	}
//
// 	glfwTerminate();
// }
