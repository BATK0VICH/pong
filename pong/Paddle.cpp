#include "Paddle.hpp"

Paddle::Paddle(const int x, const int y, const Type paddleType) :
	position(), paddleType(paddleType), paddleDirection(Direction::NONE), y(y), color("PURPLE")
{
	position.x = x;
	position.y = y;
	position.w = 50;
	position.h = 100;
}

void Paddle::handle_input(const SDL_Event &event)
{
	switch (event.type)
	{
	case SDL_KEYDOWN:
		Uint8 const* keys = SDL_GetKeyboardState(nullptr);

		if (paddleType == Type::LEFT)
		{
			if (keys[SDL_SCANCODE_W])
			{
				paddleDirection = Direction::UP;
			}
			else if (keys[SDL_SCANCODE_S])
			{
				paddleDirection = Direction::DOWN;
			}
		}
		else if (paddleType == Type::RIGHT)
		{
			if (keys[SDL_SCANCODE_UP])
			{
				paddleDirection = Direction::UP;
			}
			else if (keys[SDL_SCANCODE_DOWN])
			{
				paddleDirection = Direction::DOWN;
			}
		}
	}
}

void Paddle::update(const double delta_time)
{
	if (paddleDirection == Direction::UP)
	{
		y = y - 5.0 * delta_time;
		position.y = y;
	}
	else if (paddleDirection == Direction::DOWN)
	{
		y = y + 5.0 * delta_time;
		position.y = y;
	}
}

void Paddle::draw(SDL_Renderer* const renderer)
{
	RGBA_color colorCode = color.colorCode;
	int r{ std::get<0>(colorCode) }, g{ std::get<1>(colorCode) }, b{ std::get<2>(colorCode) };
	int alpha{ std::get<3>(colorCode) };
	SDL_SetRenderDrawColor(renderer, r, g, b, alpha);
	SDL_RenderFillRect(renderer, &position);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}