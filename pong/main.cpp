#include <iostream>
#include "SDL.h"
#include "Initialization.hpp"
#include "Helpers.hpp"
#undef main

int main(void)
{
	initializeVideo();

	SDL_Window* window = createWindow();
	checkIfWindowWasCreated(window);

	SDL_Renderer* renderer = createRenderer(window);
	checkIfRendererWasCreated(renderer);

	RGBA color(255, 99, 71, 5);
	changeWindowBackgroundColor(renderer, color);
	
	SDL_Delay(3000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}