#include "Application.h"

#include "core/Camera.h"
#include "core/Logger.h"
#include "geometry/Triangle.h"
#include "geometry/Pyramid.h"
#include "geometry/Cube.h"
#include "Ogl/GLBuffer.h"
#include "Ogl/GLShader.h"
#include "geometry/Model.h"
#include "ui/Imgui_utils.h"


Application::Application(Engine_window_attrs_t& attrs) {
	window = std::make_unique<Window>(attrs.wWidth, attrs.wHeight, attrs.title, attrs.iconPath);
	camera = std::make_unique<Camera>(window.get(), vec3{0.0, 0.0, 6.0});
	camera->SetSpeed(speed);
	
	InputManager::Init(window->GetWindowAdress());
	Init();
}

void Application::Init() {
	ImguiUI::Init(window->GetWindowAdress());

	Time::Init();
	
	logger.Log(INFO, "Starting Engine...");
}

Application::~Application() {
	glfwTerminate();
}

void Application::Run() {
	

	Model model{"../assets/objects/backpack/backpack.obj"};
	Model cat{"../assets/objects/Cat/12221_Cat_v1_l3.obj"};
	Model statue{"../assets/objects/Statue/statue.obj"};
	Model silentHill{"../assets/objects/Silent Hill 2 Baldwin Study Room Normal/Silent+Hill+2+-+Baldwin+Study+Room+-+Normal.dae"};

	GLShader shader{"../assets/shaders/vert_textures.glsl", "../assets/shaders/frag_textures.glsl"};
	
	renderer->Initialize();


	while (!glfwWindowShouldClose(window->GetWindowAdress())) {
		Time::Update();
	
		window->SetTitle(window->GetWindowTitle().append(" " + std::to_string(Time::GetFPS()) + "fps"));



		renderer->BeginFrame(clearColor);
		InputManager::Update();
        ProcessInput();
		camera->SetSpeed(speed / 1000);
		camera->SetFov(fov);

		glPolygonMode(GL_FRONT_AND_BACK, seeLine ? GL_LINE : GL_FILL);
		glfwSetInputMode(window->GetWindowAdress(), GLFW_CURSOR, cursorDisabled ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
		// glClearColor(clearColor.x, clearColor.y, clearColor.z, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		ProcessGui();

        shader.EnableShader();
		shader.SetUniformMat4("camera", camera->CalculateMatrix(0.1, farPlane));
		mat4_f baseModel = mat4_f::rotation(angle, rotation)* mat4_f::scale(scale);
		shader.SetUniformMat4("model", baseModel);


		// Scene
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

void Application::ProcessGui(){
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
				ImGui::SliderFloat("Speed", &speed, 1.0f, 15.0f);
				
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