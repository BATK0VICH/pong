#include "RGBA.hpp"


const Colors& possibleColors()
{
	static Colors colors{
		{"WHITE", RGBA_color(255, 255, 255, 1)},
		{"PURPLE", RGBA_color(255, 140, 255, 1)},
		{"BLACK", RGBA_color(0, 0, 0, 1)},
	};

	return colors;
}


RGBA::RGBA(const std::string colorName) :
	colorCode(createRGBA_colorFromStr(colorName))
{}


RGBA_color RGBA::createRGBA_colorFromStr(std::string colorName)
{
	RGBA_color selectedRGBAcolorCode = possibleColors().at(colorName);
	return selectedRGBAcolorCode;
}