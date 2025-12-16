#version 330

in vec3 Color;
in vec2 Texture;

out vec4 FragColor;

uniform sampler2D ourTexture;

void main(){
    vec4 texColor = texture(ourTexture, Texture);
    
    // Si la texture est noire, utiliser les couleurs des vertices
    if (texColor.r < 0.1 && texColor.g < 0.1 && texColor.b < 0.1) {
        FragColor = vec4(Color, 1.0);
    } else {
        FragColor = texColor;
    }
}
