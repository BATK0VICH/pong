#include "Window.hpp"
#include <stdexcept>
#include <string>
#include "RGBA.hpp"

Window::Window(const std::string title, const int height, const int width) :
	window(nullptr), height(height), width(width), title(title)
{
	this->createWindow(title.c_str(), height, width);
	this->checkIfWindowWasCreated();

	this->createRenderer();
	this->checkIfRendererWasCreated();
}

void Window::createWindow(const char* title, const int height, const int width) noexcept
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		height, width, SDL_WINDOW_OPENGL);
}

void Window::checkIfWindowWasCreated()
{
	if (window == NULL)
	{
		throw(std::runtime_error("Unable to create window"));
	}
}

void Window::createRenderer() noexcept
{
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_RenderSetLogicalSize(renderer, 400, 400);

}

void Window::checkIfRendererWasCreated()
{
	if (this->renderer == NULL)
	{
		throw(std::runtime_error("Unable to create renderer"));
	}
}

Window::~Window()
{
	SDL_DestroyWindow(this->window);
}

WindowWithBackground::WindowWithBackground(const std::string title, const int height, 
	const int width, const std::string colorName) :
	Window(title, height, width)
{
	changeBackgroundColor(colorName);
}

void WindowWithBackground::changeBackgroundColor(std::string colorName)
{
	RGBA_color RGBA_colorCode = RGBA(colorName).colorCode;
	renderColor(renderer, RGBA_colorCode);
}

void renderColor(SDL_Renderer* renderer, RGBA_color RGBA_colorCode)
{
	uint8_t red{ std::get<0>(RGBA_colorCode) };
	uint8_t green{ std::get<1>(RGBA_colorCode) };
	uint8_t blue{ std::get<2>(RGBA_colorCode) };
	uint8_t alpha{ std::get<3>(RGBA_colorCode) };
	SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}