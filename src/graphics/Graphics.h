//
// Created by robsc on 2/4/26.
//

#ifndef SILICONGRAPHICS_GRAPHICS_H
#define SILICONGRAPHICS_GRAPHICS_H



#include "../glad/glad.h"

#include "../utils/SpUtils.h"
#include "../utils/Math.h"

namespace SpGL {

struct WindowStartContext {
	int16 width, height;
	String name;
	Color clearColor;
	bool fullscreen;
};

class Graphics {
private:
	struct WindowContext {
		GLFWwindow* window;
		int16 width, height;
		int16 framebufferWidth, framebufferHeight;
		String name;
		Color clearColor;
		bool fullscreen;
	};
	public:

	Graphics() = default;

	void Init(WindowStartContext initalContext);
	void MainLoop();
	void Update();
	void Render();

	void End();

private:
	WindowContext windowContext_;

private:

	void CreateWindow();
	void DestroyWindow();
	void ResizeWindow(int width, int height);
	void ResizeFramebuffer(int width, int height);

	void InitGL();

	static void GLFWWindowSizeCallback(GLFWwindow* window, int width, int height);
	static void GLFWFramebufferSizeCallback(GLFWwindow* window, int width, int height);

};


} // SpGL

#endif //SILICONGRAPHICS_GRAPHICS_H