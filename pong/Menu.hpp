#ifndef MENU_HPP
#define MENU_HPP
#include <SDL.h>
#include "Background.hpp"


class Menu
{
private:
	Button start;
	Button options;
	Button exit;
};

class Button
{
public:
	Button(int x, int y, int w, int h);
	void show();
	void handleEvent();
	void changeBackgroundColor(std::string color);
	~Button();
private:
	SDL_Rect box;
	Background background;
};

#endif