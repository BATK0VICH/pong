#include "Background.hpp"
#include <tuple>

Background::Background() :
	renderer(nullptr), color("WHITE")
{

}

Background::Background(SDL_Window* const window, const std::string color) :
	renderer(nullptr), color(color)
{
	this->createRenderer(window);
	this->checkIfRendererWasCreated();
}

void Background::createRenderer(SDL_Window* const window) noexcept
{
	renderer = SDL_CreateRenderer(window, -1, 0);
}

void Background::checkIfRendererWasCreated()
{
	if (this->renderer == NULL)
	{
		throw(std::runtime_error("Unable to create renderer"));
	}
}

void Background::changeBackgroundColor(std::string colorName)
{
	this->checkIfRendererWasCreated();
	this->color = RGBA(color);
	RGBA_color RGBAcolorCode = color.colorCode;
	SDL_SetRenderDrawColor(this->renderer, std::get<0>(RGBAcolorCode),
		std::get<1>(RGBAcolorCode), std::get<2>(RGBAcolorCode), std::get<3>(RGBAcolorCode));
	SDL_RenderClear(this->renderer);
	SDL_RenderPresent(renderer);
}