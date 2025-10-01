//
// Created by issbe on 29/09/2025.
//

#include "ObjectLoader.h"

#include "geometry/Triangle.h"

void ObjectLoader::LoadObject(const char *path, std::vector<Vertex> *vertices, std::vector<GLuint>* indices) {
    std::ifstream file(path);
    std::string line;
    std::vector<vec3_f> temp_positions;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string prefix;
        ss >> prefix;
        if (prefix == "v") { // pos
            vec3_f pos;
            ss >> pos.x >> pos.y >> pos.z;
            temp_positions.push_back(pos);
        } else if (prefix == "f") { // face
            std::string vertexStr;
            for (int i = 0; i < 3; i++) {
                ss >> vertexStr;
                int v, t, n;
                sscanf(vertexStr.c_str(), "%d/%d/%d", &v, &t, &n);

                Vertex vert{};
                vert.position = temp_positions[v - 1];

                vertices->emplace_back(vert);
                indices->push_back(indices->size());
            }
        }
    }
}
