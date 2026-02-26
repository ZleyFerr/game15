#include "FieldCell.h"

void FieldCell::move()
{

}

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
