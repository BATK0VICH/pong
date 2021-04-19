#include "Window.hpp"
#include <stdexcept>
#include <string>
#include "RGBA.hpp"

Window::Window(const std::string title, const int height, const int width) :
	window(nullptr), height(height), width(width), title(title)
{
	this->createWindow(title.c_str(), height, width);
	this->checkIfWindowWasCreated();
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

Window::~Window()
{
	SDL_DestroyWindow(this->window);
}

WindowWithBackground::WindowWithBackground(const std::string title, const int height, 
	const int width, const std::string colorName) :
	Window(title, height, width)
{
	background = Background(window, colorName);
	background.changeBackgroundColor(colorName);
}

void WindowWithBackground::changeBackgroundColor(std::string colorName)
{
	background.changeBackgroundColor(colorName);
}