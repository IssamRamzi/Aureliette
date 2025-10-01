#version 330

in vec3 Color;
out vec4 FragColor;
in texCoords;

uniform sampler2D ourTexture;

void main(){
//    FragColor = vec4(Color, 1.0);
    FragColor = texture(ourTexture, texCoords);
}

