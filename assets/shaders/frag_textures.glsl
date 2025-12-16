#version 330

in vec3 Color;
in vec2 Texture;

out vec4 FragColor;

uniform sampler2D texture_diffuse1;

void main(){
     // Just output the diffuse texture
     FragColor = texture(texture_diffuse1, Texture);

     // Or test with texture coordinates as colors:
     // FragColor = vec4(Texture.x, Texture.y, 0.0, 1.0);
}