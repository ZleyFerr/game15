#include "position.h"

void Position::set_position(unsigned short int x, unsigned short int y)
{
	pos_now.first = x;
	pos_now.second = y;
}

std::pair <unsigned short int, unsigned short int> Position::get_position() const
{
	return pos_now;
}

Position::Position(unsigned short int x, unsigned short int y)
{
	this->pos_now.first = x;
	this->pos_now.second = y;
}
