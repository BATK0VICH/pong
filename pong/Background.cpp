#include "Background.hpp"
#include <tuple>

Background::Background() :
	renderer(nullptr), color(colors().at("WHITE"))
{

}

Background::Background(SDL_Window* const window, const std::string color) :
	renderer(nullptr), color(colors().at(color))
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

void Background::changeBackgroundColor(RGBA color)
{
	this->checkIfRendererWasCreated();
	this->color = color;
	RGBA_color RGBA_color_tuple = color.color;
	SDL_SetRenderDrawColor(this->renderer, std::get<0>(RGBA_color_tuple),
		std::get<1>(RGBA_color_tuple), std::get<2>(RGBA_color_tuple), std::get<3>(RGBA_color_tuple));
	SDL_RenderClear(this->renderer);
	SDL_RenderPresent(renderer);
}