#include "Initialization.hpp"
#include <stdexcept>
#include "SDL.h"

void initializeVideo()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		throw std::runtime_error(SDL_GetError());
	}
	return;
}

void initializeEverything()
{
	initializeVideo();
}