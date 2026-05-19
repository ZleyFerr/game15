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

void Position::position_printer_method()
{
	std::cout << "position\n";
}

Position::Position(unsigned short int x, unsigned short int y)
{
	this->x = x;
	this->x = y;
}
