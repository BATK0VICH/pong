#ifndef RGBA_HPP_
#define RGBA_HPP_

#include <cstdint>

class RGBA
{
public:
	uint8_t red, green, blue, alpha;
	RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
};


#endif