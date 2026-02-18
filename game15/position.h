#pragma once
#include <iostream>
#include <windows.h>

class Position
{
protected:
	std::pair <uint8_t, uint8_t> pos_now;
public:
	void set_position(uint8_t x, uint8_t y);
	std::pair <uint8_t, uint8_t> get_position();
};
