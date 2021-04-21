#include "Menu.hpp"
#include <SDL_clipboard.h>


Button::Button(int x, int y, int w, int h) :
	box(), clip(nullptr), background()
{
	box.x = x; 
	box.y = y; 
	box.w = w;
	box.h = h;
}

//void Button::setDefaultSprite()
//{
//	clip = &clips[CLIP_MOUSEOUT];
//}