#include "Menu.hpp"
#include <SDL_clipboard.h>
#include "Window.hpp"
#include "App.hpp"

Button::Button(int x, int y, int w, int h, Window &window) :
	box(), window(&window)
{
	box.x = x; 
	box.y = y; 
	box.w = w;
	box.h = h;
	this->show();
}

void Button::show()
{
	SDL_PixelFormat* format = surface->format;
	SDL_FillRect(surface, &box, SDL_MapRGBA(format, 255, 255, 255, 1));
	SDL_RenderFillRect(window->renderer, &box);
}

Button::~Button()
{

}

Menu::Menu(Window &window) :
	start(640, 360, 100, 100, window), options(640, 260, 100, 100, window), exit(640, 60, 100, 100, window)
{
	show();
}

void Menu::show()
{
	start.show();
	options.show();
	exit.show();
}