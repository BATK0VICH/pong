#include "Helpers.hpp"

SDL_Window* createWindow(const char* title, const int height, const int width) noexcept
{
	SDL_Window* window = nullptr;
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		height, width, SDL_WINDOW_OPENGL);
	return window;
}

void checkIfWindowWasCreated(SDL_Window* window)
{
	if (window == NULL)
	{
		throw(std::runtime_error("Unable to create window"));
	}
}

//void changeWindowBackgroundColor(SDL_Renderer* renderer, RGBA color) noexcept
//{
//	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha);
//	SDL_RenderClear(renderer);
//	SDL_RenderPresent(renderer);
//	return;
//}

SDL_Renderer* createRenderer(SDL_Window* window) noexcept
{
	SDL_Renderer* renderer = nullptr;
	renderer = SDL_CreateRenderer(window, -1, 0);
	return renderer;
}

void checkIfRendererWasCreated(SDL_Renderer* renderer)
{
	if (renderer == NULL)
	{
		throw(std::runtime_error("Unable to create renderer"));
	}
}