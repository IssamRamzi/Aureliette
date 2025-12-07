#include "Application.h"

#include "core/Camera.h"
#include "core/Logger.h"
#include "geometry/Triangle.h"
#include "geometry/Pyramid.h"
#include "Ogl/GLBuffer.h"
#include "Ogl/GLShader.h"
#include "geometry/Model.h"
#include "ui/Imgui_utils.h"


Application::Application(Engine_window_attrs_t& attrs) {
	window = new Window(attrs.wWidth, attrs.wHeight, attrs.title, attrs.iconPath);
	InputManager::Init(window->GetWindowAdress());
	camera = new Camera(window, {0.0, 0.0, 6.0});

	Init();
}

void Application::Init() {
	ImguiUI::Init(window->GetWindowAdress());
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);  // glTF standard
	logger.Log(INFO, "Starting Engine...");
}

Application::~Application() {
	glfwTerminate();
}

void Application::Run() {
	Triangle t1(vec3_f(0.0f, -0.6f, -4.0f));
	Triangle t2(vec3_f(0.0f, 0.9f, -0.5f));
	Pyramid p1 (vec3_f(3.0f, 0.9f, 2.5f));

	vec3_f scale = {1.0, 1.0, 1.0};
	vec3_f rotation = {0.0, 0.0, 0.0};

	std::vector<Vertex> cubeVertices = {
		// FRONT
		{{-1.0f, -1.0f,  1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
		{{ 1.0f, -1.0f,  1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
		{{ 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 1.0f}},
		{{-1.0f,  1.0f,  1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f}},

		// BACK
		{{ 1.0f, -1.0f, -1.0f}, {1.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
		{{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
		{{-1.0f,  1.0f, -1.0f}, {0.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
		{{ 1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},

		// LEFT
		{{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
		{{-1.0f, -1.0f,  1.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
		{{-1.0f,  1.0f,  1.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f}},
		{{-1.0f,  1.0f, -1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},

		// RIGHT
		{{ 1.0f, -1.0f,  1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
		{{ 1.0f, -1.0f, -1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
		{{ 1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
		{{ 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 0.0f}, {0.0f, 1.0f}},

		// TOP
		{{-1.0f,  1.0f,  1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
		{{ 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
		{{ 1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
		{{-1.0f,  1.0f, -1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},

		// BOTTOM
		{{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
		{{ 1.0f, -1.0f, -1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
		{{ 1.0f, -1.0f,  1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
		{{-1.0f, -1.0f,  1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
	};

	std::vector<GLuint> cubeIndices = {
		0, 1, 2, 0, 2, 3,
		4, 5, 6, 4, 6, 7,
		8, 9,10, 8,10,11,
		12,13,14, 12,14,15,
		16,17,18, 16,18,19,
		20,21,22, 20,22,23
	};
	Mesh cubeMesh{cubeVertices, cubeIndices, {}};

	vec2_f v = vec2_f::ZERO;

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

	// Mesh mesh{{
	// 	Vertex{{0.0f,  0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0, 0.0}},
	// 	Vertex{{-0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0, 0.0}},
	// 	Vertex{{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.5, 1.0}}
	// },
	// 	{0,1,2},
	// 	{}
	// };

	std::vector<Vertex> lVertices;
	std::vector<GLuint> lIndices;
	Model model{"../assets/objects/backpack/backpack.obj"};

	Model cat{"../assets/objects/Cat/12221_Cat_v1_l3.obj"};

	Model statue{"../assets/objects/Statue/statue.obj"};
	Model silentHill{"../assets/objects/Silent Hill 2 Baldwin Study Room Normal/Silent+Hill+2+-+Baldwin+Study+Room+-+Normal.dae"};
	// Model temple{"../assets/objects/temple/scene.obj"};

	Mesh modelMesh{lVertices, lIndices, {}};

	GLShader shader{"../assets/shaders/vert_textures.glsl", "../assets/shaders/frag_textures.glsl"};
	


	// GLTexture wall{"../assets/textures/wall.jpg"};
	// GLTexture face{"../assets/textures/awesomeface.png"};
	shader.EnableShader();

	shader.DisableShader();
	float angle = 0.0f;

	float fov = camera->GetFov();
	float speed = camera->GetSpeed();
	while (!glfwWindowShouldClose(window->GetWindowAdress())) {
		InputManager::Update();
        ProcessInput();
		camera->SetFov(fov);

		glPolygonMode(GL_FRONT_AND_BACK, seeLine ? GL_LINE : GL_FILL);
		glfwSetInputMode(window->GetWindowAdress(), GLFW_CURSOR, cursorDisabled ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
		glClearColor(clearColor.x, clearColor.y, clearColor.z, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ImguiUI::NewFrame();


		ImGui::Begin("Control Panel", &imguiOpen);
		{
			if (ImGui::CollapsingHeader("Camera")) {
				ImGui::SliderFloat("FOV", &fov, 45.0f, 120.0f);
				ImGui::Checkbox("Enable Cursor", &cursorDisabled);
				ImGui::Text("Position: (%.2f, %.2f, %.2f)",
							camera->GetPosition().x,
							camera->GetPosition().y,
							camera->GetPosition().z);
				ImGui::Text("Orientation: (%.2f, %.2f, %.2f)",
							camera->GetOrientation().x,
							camera->GetOrientation().y,
							camera->GetOrientation().z);
				ImGui::SliderFloat("Far Plane", &farPlane, 45.0f, 300.0f);
				
			}

			if (ImGui::CollapsingHeader("Rendering")) {
				ImGui::Checkbox("Wireframe Mode", &seeLine);
				ImGui::ColorEdit3("Clear Color", (float*)&clearColor);
				ImGui::SliderFloat3("Scale", (float*)&scale, 0.1, 10.f);
				ImGui::SliderFloat3("Rotation Axes", (float*)&rotation, 0.0, 1.0f, "%.3f", ImGuiSliderFlags_ClampOnInput);
				ImGui::SliderFloat("Rotation Angle", &angle, 0, 360);
			}
			if (ImGui::CollapsingHeader("Models")) {
				ImGui::Checkbox("Show Cat", &showCat);
				ImGui::Checkbox("Show Statue", &showStatue);
				ImGui::Checkbox("Show Backpack", &showBackpack);
				ImGui::Checkbox("Show Silent Hill", &showSilentHill);
				ImGui::Checkbox("Show Cubes", &showCubes);
			}

			if (ImGui::CollapsingHeader("Logs")) {
				ImGui::BeginChild("LogArea", ImVec2(0, 150), true, ImGuiWindowFlags_HorizontalScrollbar);
				for (auto& log : logger.GetLogs()) {
					ImGui::TextUnformatted(log.c_str());
				}
				ImGui::EndChild();
			}
		}
		ImGui::End();
        shader.EnableShader();
		shader.SetUniformMat4("camera", camera->CalculateMatrix(0.1, farPlane));
		mat4_f baseModel = mat4_f::rotation(angle, rotation)* mat4_f::scale(scale);
		shader.SetUniformMat4("model", baseModel);

		if (showCubes) {
			for (int i =0; i < cubesPositions.size(); i++) {
				vec3_f scale {cubesSize[i], cubesSize[i], cubesSize[i]};
				vec3_f rotation = vec3_f::normalize(cubesRotation[i]);
				mat4_f modelMatrix = mat4_f::translation(cubesPositions[i]) * mat4_f::rotation(angle, rotation) * mat4_f::scale(scale);

				//shader.SetUniformMat4("model", modelMatrix);
				// if (i < cubesPositions.size() / 2)
				// 	wall.Bind(0);
				// else face.Bind(1);
				shader.SetUniform1i("texture1", 0);
				shader.SetUniform1i("texture2", 1);
				cubeMesh.Draw();
			}
			// wall.Unbind();
			// face.Unbind();
		}

		if (showCat) {
			cat.Draw(shader);
		}

		if (showStatue) {
			statue.Draw(shader);
		}

		if (showBackpack) {
			model.Draw(shader);
		}
		
		if (showSilentHill) {
			silentHill.Draw(shader);
		}

		// if (showTemple) {
		// 	temple.Draw(shader);
		// }

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

	if (cursorDisabled)
		camera->ProcessMouseInputs();
	camera->ProcessKeyboardInputs();

	if (InputManager::IsKeyPressed(ESCAPE))
		exit(EXIT_SUCCESS);

	if (InputManager::IsKeyPressed(LCTRL))
		cursorDisabled = !cursorDisabled;

	if (InputManager::IsKeyPressed(ENTER))
		seeLine = !seeLine;
	
	if (InputManager::IsKeyPressed(B))
		imguiOpen = !imguiOpen;


}