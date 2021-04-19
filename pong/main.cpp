#include <iostream>
#include "SDL.h"
#include "Initialization.hpp"
#include "Helpers.hpp"
#include "Window.hpp"
#include "RGBA.hpp"
#undef main

int main(void)
{
	initializeVideo();

	WindowWithBackground window("CyberPong", 1280, 720, "PURPLE");

	
	SDL_Delay(3000);
	SDL_Quit();
	return 0;
}