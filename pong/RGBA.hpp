#ifndef RGBA_HPP_
#define RGBA_HPP_
#include <map>
#include <tuple>
#include <cstdint>
#include <string>

typedef std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> RGBA_color;
typedef std::map<std::string, RGBA_color> Colors;

const Colors& colors();

class RGBA
{
public:
	RGBA_color colorCode;
	RGBA(const std::string colorName);
private:
	RGBA_color createRGBA_colorFromStr(std::string color);
};


#endif