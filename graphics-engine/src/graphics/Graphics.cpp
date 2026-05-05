//
// Created by robsc on 2/4/26.
//

#include "Graphics.h"
#include "../utils/SpUtils.h"

namespace SpGL {
String WindowStartContext::Validate() const {
	if (width <= 0 || height <= 0) return "Set Width and Height!";
	if (name.empty()) return "Set a window name!";
	return "";
}

void Graphics::Init(WindowStartContext initalContext) {
	String validationMessage = initalContext.Validate();
	if (!validationMessage.empty()) SpUtils::Exit(validationMessage, SP_FAIL);

	windowContext_.width = initalContext.width;
	windowContext_.height = initalContext.height;
	windowContext_.name = initalContext.name;
	windowContext_.clearColor = initalContext.clearColor;
	windowContext_.fullscreen = initalContext.fullscreen;
	windowContext_.aspectRatio = static_cast<float>(windowContext_.width) / static_cast<float>(windowContext_.height);

	glfwSetErrorCallback(SpUtils::GLFWErrorCallback);

	SpUtils::ExitCheck(!glfwInit(), "Failed to initialize GLFW!", SP_GLFW_FAIL, "GLFW Init success");

	CreateWindow();
}

void Graphics::MainLoop() {
	TimeStart();

	while (!glfwWindowShouldClose(windowContext_.window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		Render();

		glfwSwapBuffers(windowContext_.window);



		CalculateTime();
		glfwPollEvents();
	}
}

void Graphics::Update() {
}

void Graphics::Render() {
	const float redColor = (time_ % 1250) / 1250.0f; // NOLINT(*-narrowing-conversions)
	const float greenColor = (static_cast<int>(time_) % 5000) / 5000.0f; // NOLINT(*-narrowing-conversions)
	const float blueColor = (static_cast<int>(time_) % 2500) / 3300.0f;  // NOLINT(*-narrowing-conversions)

	glBegin(GL_QUADS);
		glColor3f(redColor, greenColor, blueColor);
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

	windowContext_.clearColor.NormalizeColorsToOne();
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

void Graphics::TimeStart() {
	time_ = 0;
	deltaTime_ = 0;

	_deltaTimeStart_ = std::chrono::high_resolution_clock::now();

}

void Graphics::CalculateTime() {
	const std::chrono::time_point<std::chrono::system_clock> end = std::chrono::high_resolution_clock::now();

	const std::chrono::milliseconds elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - _deltaTimeStart_);

	deltaTime_ = elapsedTime.count();
	time_ += deltaTime_;

	_deltaTimeStart_ = end;
}
} //SpGL
