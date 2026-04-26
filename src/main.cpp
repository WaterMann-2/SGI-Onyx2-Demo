#include <iostream>

#include "./graphics/Graphics.h"

int main(int argc,char* argv[]) {
	SpGL::Graphics graphics;

	SpGL::WindowStartContext windowContext;
	windowContext.width = 200;
	windowContext.height = 200;
	windowContext.name = "Testing";

	windowContext.fullscreen = false;
	windowContext.clearColor = SpGL::Color(10.0f, 10.0f, 50.0f, 255.0f, false);
	
	graphics.Init(windowContext);
	graphics.MainLoop();
	graphics.End();

	return 0;
}

