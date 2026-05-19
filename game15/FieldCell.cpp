#include "FieldCell.h"

unsigned short int FieldCell::get_value() const
{
	return value;
}

bool FieldCell::get_isCellEmpty() const
{
	return isCellEmpty;
}

bool FieldCell::get_isUpAvaible() const
{
	return isUpAvaible;
}

bool FieldCell::get_isDownAvaible() const
{
	return isDownAvaible;
}

bool FieldCell::get_isLeftAvaible() const
{
	return isLeftAvaible;
}

bool FieldCell::get_isRightAvaible() const
{
	return isRightAvaible;
}

void FieldCell::set_isCellEmpty(bool status)
{
	isCellEmpty = status;
}

void FieldCell::set_isUpAvaible(bool status)
{
	isUpAvaible = status;
}

void FieldCell::set_isDownAvaible(bool status)
{
	isDownAvaible = status;
}

void FieldCell::set_isLeftAvaible(bool status)
{
	isLeftAvaible = status;
}

void FieldCell::set_isRightAvaible(bool status)
{
	isRightAvaible = status;
}

void FieldCell::set_value(unsigned short int value)
{
	this->value = value;
}

void FieldCell::updateCellStatus(bool right, bool left, bool up, bool down, bool empty)
{
	isRightAvaible = right;
	isLeftAvaible = left;
	isUpAvaible = up;
	isDownAvaible = down;
	isCellEmpty = empty;
}

void FieldCell::position_printer_method()
{
	std::cout << "position 2\n";
}
