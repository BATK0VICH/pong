#pragma once
#include <SDL.h>
#include "RGBA.hpp"

enum class Type{LEFT, RIGHT};
enum class Direction{NONE, UP, DOWN};

class Paddle
{
public:
	Paddle(const int x, const int y, const Type paddleType);
	void handle_input(const SDL_Event &event);
	void update(const double delta_time);
	void draw(SDL_Renderer* const renderer);
private:
	SDL_Rect position;
	Type paddleType;
	Direction paddleDirection;
	double y;
	RGBA color;
};

