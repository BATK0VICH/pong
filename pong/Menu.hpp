#ifndef MENU_HPP
#define MENU_HPP
#include <SDL.h>

class Menu
{

};

class Button
{
public:
	Button(int x, int y, int w, int h);
	void show();
	void handleEvent();
	~Button();
private:
	SDL_Rect box;
	SDL_Rect* clip;
	void setDefaultSprite();
};

#endif