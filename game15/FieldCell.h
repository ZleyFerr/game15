#pragma once
#include "position.h"

class FieldCell : public Position
{
protected:
	unsigned short int value = 0;
	bool isCellEmpty = false;
	bool isUpAvaible = false;
	bool isDownAvaible = false;
	bool isLeftAvaible = false;
	bool isRightAvaible = false;
public:
	FieldCell(unsigned short int value, bool isCellEmpty,	bool isUpAvaible, bool isDownAvaible, bool isLeftAvaible, bool isRightAvaible)
		: value{ value },	isCellEmpty{ isCellEmpty }, isUpAvaible{ isUpAvaible }, isDownAvaible{ isDownAvaible },	isLeftAvaible{ isLeftAvaible }, isRightAvaible{ isRightAvaible } {};
	FieldCell() {};
	void move();
	unsigned short int get_value() const;
	bool get_isCellEmpty()const;
	bool get_isUpAvaible()const;
	bool get_isDownAvaible()const;
	bool get_isLeftAvaible()const;
	bool get_isRightAvaible()const;

	void set_isCellEmpty(bool status);
	void set_isUpAvaible(bool status);
	void set_isDownAvaible(bool status);
	void set_isLeftAvaible(bool status);
	void set_isRightAvaible(bool status);

	void updateCellStatus(bool right, bool left, bool up, bool down, bool empty);
};