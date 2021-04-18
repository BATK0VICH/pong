#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SDL.h>
#include <string>
#include "Background.hpp"
#include "RGBA.hpp"

class Window
{
public:
	SDL_Window* window;
private:
	int height, width;
	std::string title;
	Background background;
public:
	Window(const std::string title, const int height, const int width, const std::string color);
	void changeBackgroundColor(RGBA color);
	~Window();
private:
	void createWindow(const char* title, const int height, const int width) noexcept;
	void checkIfWindowWasCreated();
};

#endif
