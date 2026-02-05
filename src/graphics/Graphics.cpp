//
// Created by robsc on 2/4/26.
//

#include "Graphics.h"

namespace SpGL {
void Graphics::HelloWorld() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	std::printf("Glfw Init?");
}
} // SpGL