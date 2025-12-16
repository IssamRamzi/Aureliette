#include "Scene.hpp"


Scene::Scene(){

} 
void Scene::AddModel(std::shared_ptr<Model> model){
    m_models.emplace_back(model);
}

void Scene::Render(Renderer& renderer){
    for(auto model : m_models){
        model->Draw(*renderer.GetCurrentShader());
    }
}

void Scene::Update(float deltaTime){
    
}
