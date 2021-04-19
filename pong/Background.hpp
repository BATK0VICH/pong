#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#include <SDL.h>
#include "RGBA.hpp"
#include <stdexcept>

class Background
{
public:
	SDL_Renderer* renderer;
private:
	RGBA color;
public:
	Background();
	Background(SDL_Window* const window, const std::string colorName);
	void changeBackgroundColor(std::string colorName);
private:
	void createRenderer(SDL_Window* const window) noexcept;
	void checkIfRendererWasCreated();
};
#endif


