#include "position.h"

void Position::set_position(uint8_t x, uint8_t y)
{
	pos_now.first = x;
	pos_now.second = y;
}


std::pair <uint8_t, uint8_t> Position::get_position()
{
	return pos_now;
}