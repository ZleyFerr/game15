#include "FieldCell.h"

void FieldCell::move()
{

}

uint8_t FieldCell::get_value()
{
	return value;
}

std::pair<uint8_t, uint8_t> FieldCell::get_position()
{
	return position;
}

bool FieldCell::get_isCellEmpty()
{
	return isCellEmpty;
}

bool FieldCell::get_isUpAvaible()
{
	return isUpAvaible;
}

bool FieldCell::get_isDownAvaible()
{
	return isDownAvaible;
}

bool FieldCell::get_isLeftAvaible()
{
	return isLeftAvaible;
}

bool FieldCell::get_isRightAvaible()
{
	return isRightAvaible;
}
