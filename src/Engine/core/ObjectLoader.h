//
// Created by issbe on 29/09/2025.
//
#pragma once
#ifndef OBJECTLOADER_H
#define OBJECTLOADER_H
#include <memory>
#include <vector>

#include "../geometry/Vertex.h"


class ObjectLoader {
public:
    static void LoadObject(const char *path, std::vector<Vertex> *vertices, std::vector<GLuint>* indices);
// static void LoadObject(const char *path, std::unique_ptr<std::vector<Vertex>> vertices, std::unique_ptr<std::vector<GLuint>> indices) {

};



#endif //OBJECTLOADER_H
