//
// Created by issbe on 21/09/2025.
//
#include "Utils.h"

#include <iostream>


std::string GetTextFromFile(const std::string& filename) {
    FILE* file;
    fopen_s(&file, filename.c_str(), "rt");
    if (!file) {
        std::cout << filename.c_str() << " not found" << std::endl;
        return "";
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    std::string content;
    content.reserve(size);

    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c >= 0 && c <= 127) {
            content.push_back(c);
        } else {
            content.push_back(' ');
        }
    }

    fclose(file);
    return content;
}
