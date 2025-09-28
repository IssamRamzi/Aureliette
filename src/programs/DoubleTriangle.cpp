// #include "Application.h"
//
// #include "core/Camera.h"
// #include "core/Logger.h"
// #include "geometry/Triangle.h"
// #include "Ogl/GLBuffer.h"
// #include "Ogl/GLShader.h"
//
// Application::Application(std::string title, int width, int height) {
//     window = new Window(width, height, title);
//     Init();
// }
//
// void Application::Init() {
//     logger.Log(INFO, "Starting Engine...");
//     InputManager::Init(window->GetWindowAdress());
//     camera = new Camera(window, {0.0, 0.0, 6.0});
// }
//
// void Application::Run() {
//     std::vector<Vertex> vertices = {
//         Vertex{{0.0f,  0.5f, 0.0f}, {1.0f, 0.0f, 0.5f}},
//         Vertex{{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 1.0f}},
//         Vertex{{0.5f, -0.5f, 0.0f}, {0.0f, 0.3f, 1.0f}}
//     };
//     std::vector<GLuint> indices = {0,1,2};
//
//     Mesh *triangleMesh = new Mesh{
//         vertices, indices
//     };
//     Triangle t1(triangleMesh, vec3_f(0.0f, -0.6f, -0.6f));
//     Triangle t2(triangleMesh, vec3_f(0.0f, 0.9f, -0.9f));
//
//     GLShader shader{"../shaders/vert_camera.glsl", "../shaders/frag_camera.glsl"};
//     while (!glfwWindowShouldClose(window->GetWindowAdress())) {
//         InputManager::getPressedKeys();
//         ProcessInput();
//
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);
//
//         shader.EnableShader();
//
//         mat4_f view{1.0};
//         mat4_f projection = mat4_f::orthographic(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
//         shader.SetUniformMat4("view", view);
//         shader.SetUniformMat4("projection", projection);
//
//
//
//         t1.Draw(shader);
//         t2.Draw(shader);
//
//         shader.DisableShader();
//
//         glfwSwapBuffers(window->GetWindowAdress());
//         glfwPollEvents();
//     }
//
//     glfwTerminate();
// }
//
//
// void Application::ProcessInput() {
//     camera->ProcessKeyboardInputs();
//     if (InputManager::IsKeyPressed(ESCAPE)) {
//         exit(EXIT_SUCCESS);
//     }
// }
