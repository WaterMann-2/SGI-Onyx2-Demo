//
// Created by robsc on 2/4/26.
//

#ifndef SILICONGRAPHICS_GRAPHICS_H
#define SILICONGRAPHICS_GRAPHICS_H



#include "../glad/glad.h"

#include "../utils/SpUtils.h"
#include "../math/Math.h"

namespace SpGL {

struct WindowStartContext {
	int16 width, height;
	String name;
	Color clearColor;
	bool fullscreen;

	String Validate() const;
};

class Graphics {
private:
	struct WindowContext {
		GLFWwindow* window;
		int16 width, height;
		int16 framebufferWidth, framebufferHeight;
		String name;
		float aspectRatio;
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

	std::chrono::time_point<std::chrono::system_clock> _deltaTimeStart_;
	///Time in Milliseconds since start
	long time_ = 0;
	///Time in Milliseconds since last frame
	long deltaTime_ = 0;

private:

	void CreateWindow();
	void DestroyWindow();
	void ResizeWindow(int width, int height);
	void ResizeFramebuffer(int width, int height);

	void InitGL();

	static void GLFWWindowSizeCallback(GLFWwindow* window, int width, int height);
	static void GLFWFramebufferSizeCallback(GLFWwindow* window, int width, int height);

	void TimeStart();
	void CalculateTime();

};


} // SpGL

#endif //SILICONGRAPHICS_GRAPHICS_H