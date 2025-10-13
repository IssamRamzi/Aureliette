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
#include "../../impl/Ogl/GLTexture.h"
#include "Ogl/GLShader.h"

class Mesh;

class Model {
private:
    std::vector<Mesh> m_meshes;
    std::string directory;

    void Load();
public:
    Model(std::string path);
    void Draw(GLShader& shader);
};




#endif //MODEL_H
