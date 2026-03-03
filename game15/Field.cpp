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
		int zeroIndex = getCellIndex(0), cellIndex = getCellIndex(i);

		gameField[i].set_isDownAvaible(0);
		gameField[i].set_isUpAvaible(0);
		gameField[i].set_isRightAvaible(0);
		gameField[i].set_isLeftAvaible(0);
		if (gameField[i].get_value() == 0)
		{
			gameField[i].set_isCellEmpty(1);
		}

		int line = i / size;
		if (i != (sizeInSquare - 1)) // вправо
		{
			if (i+1 == zeroIndex) 
				gameField[i].set_isRightAvaible(1);
			else
				gameField[i].set_isRightAvaible(0);
		}


		if (i != 0) // влево
		{
			if (gameField[i - 1].get_isCellEmpty())
				gameField[i].set_isLeftAvaible(1);
			else
				gameField[i].set_isLeftAvaible(0);
		}

		if (i-size >= 0) //верх
		{
			if(gameField[i-size].get_isCellEmpty())
				gameField[i].set_isUpAvaible(1);
			else
				gameField[i].set_isUpAvaible(0);
		}

		if (i+size < sizeInSquare) //вниз
		{
			if (gameField[i + size].get_isCellEmpty())
				gameField[i].set_isDownAvaible(1);
			else
				gameField[i].set_isDownAvaible(0);
		}
	}
}

bool isMoveAvaiable(FieldCell& cell)
{
	return (cell.get_isDownAvaible() || cell.get_isLeftAvaible() || cell.get_isRightAvaible() || cell.get_isUpAvaible());
}

int getCellIndex(int value)
{
	auto cellIterator = std::find_if(gameField.begin(), gameField.end(),
		[&value](const FieldCell& cell) {return cell.get_value() == value; });
	int index = std::distance(gameField.begin(), cellIterator);
	return index;
}

bool checkWin()
{
	for (int i = 0; i < gameField.size(); i++)
	{
		if (gameField[i].get_value() != i)
		{
			return 0;
		}
	}
	return 1;
}

void changeCells(int size)
{
	updateFieldCellsStatuses(size);
	int sizeInSquare = size * size;
	setlocale(LC_ALL, "Ru");
	int cellToChange = -1;

	while (cellToChange < 1 || cellToChange > (sizeInSquare-1))
	{
		std::cout << "Введите клетку [1-" << sizeInSquare-1 <<  "] которую хотите поменять местами с клеткой 0: ";
		std::cin >> cellToChange;
		if (std::cin.fail() || cellToChange > (sizeInSquare - 1))
		{
			std::cin.clear();
			std::cin.ignore();
		}
	}
	
	FieldCell cellToCheck = gameField[getCellIndex(cellToChange)];
	if (!isMoveAvaiable(cellToCheck))
	{
		cellToChange = -1;
		system("cls");
		std::cout << "Ход недоступен, смените клетку.\n";
	}
	else
	{
		int zeroIndex = getCellIndex(0), cellIndex = getCellIndex(cellToChange);;
		if ((gameField[cellIndex].get_x() == size) && (gameField[cellIndex].get_x() == 1))
			std::cout << "Ход недоступен, смените клетку.\n";
		else 
		{
			FieldCell tempCell = gameField[cellIndex];
			gameField[cellIndex] = gameField[zeroIndex];
			gameField[zeroIndex] = tempCell;
			system("cls");
		}
	}
}





