#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SDL.h>
#include <string>
#include "RGBA.hpp"

class Window
{
public:
	SDL_Window* window;
	SDL_Renderer* renderer;
private:
	int height, width;
	std::string title;
public:
	Window(const std::string title, const int height, const int width);
	~Window();
private:
	void createWindow(const char* title, const int height, const int width) noexcept;
	void checkIfWindowWasCreated();

	void createRenderer() noexcept;
	void checkIfRendererWasCreated();
};

class WindowWithBackground : public Window
{
public:
	WindowWithBackground(const std::string title, const int height, 
		const int width, const std::string color);
	void changeBackgroundColor(std::string color);
};

void renderColor(SDL_Renderer* renderer, RGBA_color RGBA_colorCode);

#endif

