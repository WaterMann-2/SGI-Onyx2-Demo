//
// Created by robsc on 2/4/26.
//

#include "Graphics.h"

namespace SpGL {
void Graphics::HelloWorld() {

	SDL_Window* window = nullptr;

	SDL_Surface* surface = nullptr;

	if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
		std::printf("SDL Failed to initialize!\nSDL_Error: %s\n", SDL_GetError());
		std::exit(GL_SDL_ERROR);
	}
	std::printf("SDL initialized (YIPEE)");

	window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 200, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::printf("SDL Window creation failed!\nSDL_Error: %s\n", SDL_GetError());
		std::exit(GL_SDL_ERROR);
	}

	surface = SDL_GetWindowSurface(window);
	SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 255, 0, 255));
	SDL_UpdateWindowSurface(window);

	SDL_Event event;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

}

void Graphics::Start() {

	{
		WindowContextInfo windowCreateInfo = {};
		windowContext.fullscreen = false;
		windowContext.width = 400;
		windowContext.height = 400;
		windowContext.title = "Demo Project";
		windowContext.windowName = windowContext.title;

		createWindow(windowCreateInfo, windowContext);
	}


}

void Graphics::createWindow(WindowContextInfo& pWindowCreateInfo, WindowContext& windowContext) {
}
} // SpGL