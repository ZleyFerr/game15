#pragma once
#include <iostream>
#include <windows.h>
#include <utility>

class Position
{
protected:
	std::pair <unsigned short int, unsigned short int> pos_now = { 0,1 };
public:
	void set_position(unsigned short int x, unsigned short int y);
	std::pair <unsigned short int, unsigned short int> get_position() const;
	Position(unsigned short int x, unsigned short int y);
	Position() {};
};
