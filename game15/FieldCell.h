#pragma once
#include "position.h"

class FieldCell
{
protected:
	uint8_t value;
	std::pair<uint8_t, uint8_t> position;
	bool isCellEmpty;
	bool isUpAvaible;
	bool isDownAvaible;
	bool isLeftAvaible;
	bool isRightAvaible;
public:
	void move();
	uint8_t get_value();
	std::pair<uint8_t, uint8_t> get_position();
	bool get_isCellEmpty();
	bool get_isUpAvaible();
	bool get_isDownAvaible();
	bool get_isLeftAvaible();
	bool get_isRightAvaible();
};