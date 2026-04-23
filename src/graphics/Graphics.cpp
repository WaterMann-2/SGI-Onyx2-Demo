//
// Created by robsc on 2/4/26.
//

#include "Graphics.h"
#include "../utils/SpUtils.h"

namespace SpGL {

void Graphics::Init(WindowStartContext initalContext) {
	windowContext_.width = initalContext.width;
	windowContext_.height = initalContext.height;
	windowContext_.name = initalContext.name;
	windowContext_.clearColor = initalContext.clearColor;
	windowContext_.fullscreen = initalContext.fullscreen;

	glfwSetErrorCallback(SpUtils::GLFWErrorCallback);

	SpUtils::ExitCheck(!glfwInit(), "Failed to initialize GLFW!", SP_GLFW_FAIL, "GLFW Init success");

	CreateWindow();
}

void Graphics::MainLoop() {
	while (!glfwWindowShouldClose(windowContext_.window)) {
		glfwPollEvents();
	}
}

void Graphics::Update() {
}

void Graphics::End() {


	glfwTerminate();
}


void Graphics::CreateWindow() {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	windowContext_.window = nullptr;
	windowContext_.window = glfwCreateWindow(windowContext_.width, windowContext_.height, windowContext_.name.c_str(), nullptr, nullptr);

	if (windowContext_.window == nullptr) SpUtils::Exit("Failed to create GLFW window", SP_GLFW_FAIL);

	glfwMakeContextCurrent(windowContext_.window);
	gladLoadGL();


}

void Graphics::DestroyWindow() {

	glfwDestroyWindow(windowContext_.window);
}

void Graphics::InitGL() {

}
} //SpGL
