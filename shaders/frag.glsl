#version 330 core
out vec4 FragColor;

uniform vec4 color = vec4(0.3, 0.2, 0.5, 1.0);

void main()
{
    FragColor = color;
}