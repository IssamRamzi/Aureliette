// STARTER CODE FROM learnopengl.com

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include "core/tiny_obj_loader.h"

#include <iostream>

#include "Application.h"
#include "Utils.h"

int main() {
	Engine_window_attrs_t attributs{.title = "Aureliette", 1600, 900, "../assets/config/aureliette-logo.png"};
	Application application{attributs};
	application.Run();

	return 0;
}
