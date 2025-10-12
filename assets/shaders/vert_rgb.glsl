#version 330 core

layout(location = 0) in vec3 aPos;    // position des sommets
layout(location = 1) in vec3 aColor;  // couleur des sommets

out vec3 Color;  // sortie vers le fragment shader

void main() {
    gl_Position = vec4(aPos, 1.0);
    Color = aColor;                // passer la couleur
}
