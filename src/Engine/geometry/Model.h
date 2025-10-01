//
// Created by issbe on 30/09/2025.
//

#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <iostream>
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include "core/Texture.h"
#include "Ogl/GLShader.h"

class Mesh;

class Model {
private:
    std::vector<Mesh> m_meshes;
    std::string directory;

    void LoadModel(std::string path);
    void ProcessNode(aiNode* node, const aiScene* scene);
    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<Texture> LoadTextures(aiMaterial *mat, aiTextureType type, std::string nametype);

public:
    Model(std::string path);
    void Draw(GLShader& shader);
};




#endif //MODEL_H
