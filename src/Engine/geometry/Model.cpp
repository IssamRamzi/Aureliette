//
// Created by issbe on 30/09/2025.
//

#include "Model.h"

#include "Mesh.h"

Model::Model(std::string path) {
}

void Model::Draw(GLShader& shader) {
    shader.EnableShader();
    for (auto& mesh : m_meshes) {
        mesh.Draw();
    }
    shader.EnableShader();

}

