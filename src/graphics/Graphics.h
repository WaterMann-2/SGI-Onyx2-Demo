//
// Created by robsc on 2/4/26.
//

#ifndef SILICONGRAPHICS_GRAPHICS_H
#define SILICONGRAPHICS_GRAPHICS_H

#include "../glad/glad.h"
#include <SDL2/SDL.h>

#include "../utils/Utils.h"

namespace SpGL {
class Graphics {
	public:

	void HelloWorld();

	struct WindowContext {
		SDL_Window* window;
		int16 width, height;
		String title;
		String windowName;
		bool fullscreen;
	};

	void Start();

private:
	struct WindowContextInfo{
		int16 width, height;
		String title;
		String windowName;
		bool fullscreen;
	};

private:
	WindowContext windowContext;

	void createWindow(WindowContextInfo& pWindowCreateInfo, WindowContext& windowContext);

};
} // SpGL

#endif //SILICONGRAPHICS_GRAPHICS_H