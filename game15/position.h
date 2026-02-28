#pragma once
#include <iostream>
#include <windows.h>
#include <utility>

class Position
{
protected:
	unsigned short int x = 0;
	unsigned short int y = 0;
public:
	void set_position(unsigned short int x, unsigned short int y);
	unsigned short int get_x() const;
	unsigned short int get_y() const;
	Position(unsigned short int x, unsigned short int y);
	Position() {};
};
