#include "Window.hpp"
#include <stdexcept>
#include <string>

Window::Window(const std::string title, const int height, const int width, const std::string color) :
	window(nullptr), height(height), width(width), title(title)
{
	this->createWindow(title.c_str(), height, width);
	this->checkIfWindowWasCreated();
	background = Background(window, color);
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

void Window::changeBackgroundColor(RGBA color)
{
	this->background.changeBackgroundColor(color);
}

Window::~Window()
{
	SDL_DestroyWindow(this->window);
}