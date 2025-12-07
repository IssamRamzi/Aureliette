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
class GLTexture;
class Model {
private:
    std::vector<std::shared_ptr<GLTexture>> m_textures;
    std::vector<Mesh> m_meshes;
    std::string m_directory;

    void Load(std::string&);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<std::shared_ptr<GLTexture>> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
public:
    Model(std::string path);
    void Draw(GLShader& shader);
};




#endif //MODEL_H
