// #include "Application.h"
//
// #include "core/Logger.h"
// #include "Ogl/GLBuffer.h"
// #include "Ogl/GLIndexBuffer.h"
//
// #include "Ogl/GLShader.h"
// #include "Ogl/GLVertexArrayBuffer.h"
//
// Application::Application(std::string title, int width, int height){
// 	// Logger::Init("logs.txt");
// 	Init();
// 	window = new Window(width, height, title);
// }
//
// void Application::Init(){
// }
//
// void Application::Run(){
// 	GLfloat vertices[] = {
// 		-0.5f,  0.5f, 0.0f,
// 		-0.5f, -0.5f, 0.0f,
// 		 0.5f, -0.5f, 0.0f,
// 		 0.5f,  0.5f, 0.0f
// 	};
//
// 	GLuint indices[] = {
// 		0, 1, 2,
// 		2, 3, 0
// 	};
//
// 	GLVertexArrayBuffer VAO{};
// 	GLBuffer VBO{vertices, 3, 12};
// 	GLIndexBuffer EBO{indices, 6};
// 	VAO.AddBuffer(VBO, 0, 3, 3 * sizeof(GL_FLOAT), (void*)0);
//
//
// 	GLShader shader{"../shaders/vert.glsl", "../shaders/frag.glsl"};
//
// 	float i = 0.0;
// 	while (!glfwWindowShouldClose(window->GetWindowAdress())) {
// 		if (i >= 1.0) i = 0;
//
// 		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
// 		glClear(GL_COLOR_BUFFER_BIT);
//
// 		shader.EnableShader();
// 		VAO.Bind();
// 		EBO.Bind();
// 		glDrawElements(GL_TRIANGLES, EBO.GetCount(), GL_UNSIGNED_INT, 0);
//
// 		shader.DisableShader();
//
// 		EBO.Unbind();
// 		VAO.UnBind();
//
// 		glfwSwapBuffers(window->GetWindowAdress());
// 		glfwPollEvents();
// 	}
//
// 	glfwTerminate();
// }
