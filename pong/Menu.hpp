#ifndef MENU_HPP
#define MENU_HPP
#include <SDL.h>
#include <string>
#include "Window.hpp"

class Button
{
public:
	Button(int x, int y, int w, int h, Window &window);
	void show();
	void handleEvent();
	void changeBackgroundColor(std::string color);
	~Button();
private:
	SDL_Rect box;
	SDL_Surface* surface;
	Window* window;
};


class Menu
{
private:
	Button start;
	Button options;
	Button exit;
public:
	Menu(Window &window);
	void show();
	void hide();
};

#endif