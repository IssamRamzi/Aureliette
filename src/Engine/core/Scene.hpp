#ifndef SCENE_H
#define SCENE_H

#pragma once

#include <memory>
#include<vector>


#include "Renderer.hpp"
#include "geometry/Model.h"

class Scene
{
private:
    std::vector<std::shared_ptr<Model>> m_models;

public:
    Scene();
    
    void AddModel(std::shared_ptr<Model> model);
    void Render(Renderer& renderer);
    void Update(float deltaTime);
};

#endif // SCENE_H
