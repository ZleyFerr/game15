#pragma once
#include "position.h"

class FieldCell : public Position
{
protected:
	unsigned short int value;
	bool isCellEmpty;
	bool isUpAvaible;
	bool isDownAvaible;
	bool isLeftAvaible;
	bool isRightAvaible;
public:
	FieldCell(unsigned short int value, Position pos, bool isCellEmpty,
		bool isUpAvaible, bool isDownAvaible, bool isLeftAvaible, bool isRightAvaible) : value{ value }, isCellEmpty{ isCellEmpty }, isUpAvaible{ isUpAvaible }, isDownAvaible{ isDownAvaible },
		isLeftAvaible{ isLeftAvaible }, isRightAvaible{ isRightAvaible } 
	{
		pos_now.first = pos.get_position().first; 
		pos_now.second = pos.get_position().second;
	};
	void move();
	unsigned short int get_value();
	bool get_isCellEmpty();
	bool get_isUpAvaible();
	bool get_isDownAvaible();
	bool get_isLeftAvaible();
	bool get_isRightAvaible();
};