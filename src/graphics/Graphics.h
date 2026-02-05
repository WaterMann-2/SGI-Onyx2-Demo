//
// Created by robsc on 2/4/26.
//

#ifndef SILICONGRAPHICS_GRAPHICS_H
#define SILICONGRAPHICS_GRAPHICS_H

#include "../glad/glad.h"
#include <GLFW/glfw3.h>

#include "../utils/Utils.h"

namespace SpGL {
class Graphics {
	public:

	void HelloWorld();

	struct WindowContext {
		GLFWwindow* window;
		int16 width, height;
		std::string title;
		std::string windowName;
	};

};
} // SpGL

#endif //SILICONGRAPHICS_GRAPHICS_H