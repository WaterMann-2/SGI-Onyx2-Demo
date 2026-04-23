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
		glClear(GL_COLOR_BUFFER_BIT);

		Render();

		glfwSwapBuffers(windowContext_.window);
		glfwPollEvents();
	}
}

void Graphics::Update() {
}

void Graphics::Render() {
	glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
	glEnd();
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

	glClearColor(windowContext_.clearColor.r, windowContext_.clearColor.g, windowContext_.clearColor.b, windowContext_.clearColor.a);

	glfwSetWindowUserPointer(windowContext_.window, this);
	glfwSetFramebufferSizeCallback(windowContext_.window, Graphics::GLFWFramebufferSizeCallback);
	glfwSetWindowSizeCallback(windowContext_.window, Graphics::GLFWWindowSizeCallback);
}

void Graphics::DestroyWindow() {

	glfwDestroyWindow(windowContext_.window);
}

void Graphics::ResizeWindow(int width, int height) {
	windowContext_.width = static_cast<int16>(width);
	windowContext_.height = static_cast<int16>(height);

	glViewport(0, 0, windowContext_.width, windowContext_.height);
}

void Graphics::ResizeFramebuffer(int width, int height) {
	windowContext_.framebufferWidth = static_cast<int16>(width);
	windowContext_.framebufferHeight = static_cast<int16>(height);
}

void Graphics::InitGL() {

}

void Graphics::GLFWWindowSizeCallback(GLFWwindow* window, int width, int height) {

}

void Graphics::GLFWFramebufferSizeCallback(GLFWwindow* window, int width, int height) {
	Graphics* graphics = static_cast<Graphics*>(glfwGetWindowUserPointer(window));

	graphics->ResizeWindow(width, height);
}

} //SpGL
