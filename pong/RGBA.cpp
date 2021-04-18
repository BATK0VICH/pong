#include "RGBA.hpp"

const Colors& colors()
{
	static Colors colors{
		{"WHITE", RGBA_color(255, 255, 255, 1)},
		{"PURPLE", RGBA_color(255, 140, 255, 1)},
		{"BLACK", RGBA_color(0, 0, 0, 1)},
	};

	return colors;
}


RGBA::RGBA(const RGBA_color color) :
	color(color)
{}