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

	void InitGL();

};


} // SpGL

#endif //SILICONGRAPHICS_GRAPHICS_H