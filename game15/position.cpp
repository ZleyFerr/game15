#include "position.h"

void Position::set_position(unsigned short int x, unsigned short int y)
{
	this->x = x;
	this->y = y;
}

unsigned short int Position::get_x() const
{
	return x;
}

unsigned short int Position::get_y() const
{
	return y;
}

Position::Position(unsigned short int x, unsigned short int y)
{
	this->x = x;
	this->x = y;
}
