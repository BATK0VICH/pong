#ifndef HELPERS_HPP
#define HELPERS_HPP
#include <SDL.h>
#include <string>
#include <stdexcept>
#include "RGBA.hpp"

SDL_Window* createWindow(const char* title, const int height, const int width) noexcept;
void checkIfWindowWasCreated(SDL_Window* window);

void changeWindowBackgroundColor(SDL_Renderer* renderer, RGBA color) noexcept;

SDL_Renderer* createRenderer(SDL_Window* window) noexcept;
void checkIfRendererWasCreated(SDL_Renderer* renderer);

#endif 


