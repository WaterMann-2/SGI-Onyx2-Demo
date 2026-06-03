#include <Graphics.h>


int main(int argc,char* argv[]) {
	SpEngine::Graphics graphics;

	SpEngine::WindowStartContext windowContext;
	windowContext.width = 200;
	windowContext.height = 200;
	windowContext.name = "Testing";

	windowContext.fullscreen = false;
	windowContext.clearColor = glm::vec4(10.0f, 10.0f, 50.0f, 255.0f);

	glm::vec<4, float> awesomeColor = glm::vec<4, float>(1.0f);
	glm::vec<4, float> newAwesome = glm::vec<4, float>(1.0f);
	awesomeColor = newAwesome;

	graphics.Init(windowContext);
	graphics.MainLoop();
	graphics.End();

	return 0;
}

