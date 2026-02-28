#include "Field.h"
std::vector <FieldCell> gameField;
std::set<int> FieldUnical; 

void createField(unsigned short int size)
{
	unsigned int sizeInSquare = size * size;
	std::mt19937 seed(std::random_device{}());
	std::uniform_int_distribution<unsigned short int> generate (0, sizeInSquare-1);
	
	unsigned short int stroka = 1;
	unsigned short int stolbec = 1;
	for (unsigned int i = 1; i <= sizeInSquare; i++)
	{
		unsigned short int value = generate(seed);
		while(!(FieldUnical.find(value) == FieldUnical.end()))
			value = generate(seed);
		FieldUnical.insert(value);

		if (i < size*stroka)
		{
			FieldCell cell(value, false, false, false, false, false);
			cell.set_position(stroka, stolbec);
			gameField.push_back(cell);
			stolbec++;
		}
		else if (i == size*stroka)
		{
			FieldCell cell(value, false, false, false, false, false);
			cell.set_position(stroka, stolbec);
			gameField.push_back(cell);
			stroka++;
			stolbec = 1;
		}
	}
}

void printField(int size)
{
	unsigned short int stroka = 1;
	unsigned short int stolbec = 1;
	int sizeInSquare = size * size;

	for (unsigned int i = 1; i <= sizeInSquare; i++)
	{
		if (i < size * stroka)
		{
			if(gameField[i - 1].get_value() > 9)
				std::cout << "["  << gameField[i - 1].get_value() << "]  ";
			else 
				std::cout << "[" << gameField[i - 1].get_value() << "]   ";
			stolbec++;
		}
		else if (i == size * stroka)
		{
			std::cout << "[" <<  gameField[i-1].get_value() << "]" << "\n\n";
			stroka++;
			stolbec = 1;
		}
	}
}

void updateFieldCellsStatuses(int size)
{
	int sizeInSquare = size * size;

	for (int i = 0; i < sizeInSquare; i++)
	{
		unsigned int cellX = gameField[i].get_x(), cellY = gameField[i].get_y();
		int upperX = -1, downX = -1, leftY = -1, rightY = -1;

		if (i != (sizeInSquare - 1)) // вправо
		{
			if (gameField[i + 1].get_value() == 0) 
				gameField[i].set_isRightAvaible(1);
		}

		if (i != 0) // влево
		{
			if (gameField[i - 1].get_value() == 0)
				gameField[i].set_isLeftAvaible(1);
		}

		if (gameField[i].get_x() > 1) //верх
		{
			if(gameField[i-size].get_x() == 0)
				gameField[i].set_isUpAvaible(1);
		}

		if (gameField[i].get_x() < size) //вниз
		{
			if (gameField[i + size].get_x() == 0)
				gameField[i].set_isDownAvaible(1);
		}

	}
}



