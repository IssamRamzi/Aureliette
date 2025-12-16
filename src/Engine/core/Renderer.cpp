#include "Renderer.hpp"

#include "Camera.h"
#include "geometry/Mesh.h"
#include "ogl/GLShader.h"


Renderer::Renderer() : m_camera(nullptr), m_currentShader(nullptr), m_rendererMode(RendererMode::Fill), m_viewportX(0), m_viewportY(0) {}

Renderer::~Renderer(){

}

void Renderer::Initialize(){
    logger.Log(INFO, "Initializing Renderer...");
    glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW); // pour gltf

    logger.Log(INFO, "Logger Initialized Successfully");
}


void Renderer::BeginFrame(const vec3_f& clearColor) {
    glClearColor(clearColor.x, clearColor.y, clearColor.z, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



}


void Renderer::SetCamera(Camera* camera){
    m_camera = camera;
}

void Renderer::SetViewport(int x, int y, int width, int height){
    m_viewportX = x, m_viewportY = y;
    m_viewportWidth = width, m_viewportHeight = height;
    glViewport(x, y, width, height);
}

void Renderer::GetViewport(int& x, int& y, int& width, int& height) const {
    x = m_viewportX, y = m_viewportY;
    width = m_viewportWidth, height = m_viewportHeight;
}

void Renderer::UseShader(GLShader* shader){
    if(shader != m_currentShader){
        if(shader){
            shader->EnableShader();
            m_currentShader = shader;
        }
        else{
            if(m_currentShader){
                m_currentShader->DisableShader();
            }
            m_currentShader = nullptr;
        }
    }
}

void Renderer::DrawMesh(Mesh* mesh, const mat4_f& modelMatrix){
}
