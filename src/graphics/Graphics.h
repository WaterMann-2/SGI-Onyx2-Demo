//
// Created by robsc on 2/4/26.
//

#ifndef SILICONGRAPHICS_GRAPHICS_H
#define SILICONGRAPHICS_GRAPHICS_H

#include "../glad/glad.h"

#include "../utils/SpUtils.h"
#include "../utils/Math.h"

namespace SpGL {

struct WindowContext {
	WindowContext();
	window;
	surface;
	glContext;
	int16 width, height;
	String title;
	String windowName;
	Color clearColor;
	bool fullscreen;
};

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class Graphics {
	public:

	Graphics();

private:
	bool quit = false;
	WindowContext windowContext;


private:

};
} // SpGL

#endif //SILICONGRAPHICS_GRAPHICS_H