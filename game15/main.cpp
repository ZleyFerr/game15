#include "Field.h"

int main()
{
	const int size = 4;
	createField(size);
	while (true)
	{
		printField(size);
		updateFieldCellsStatuses(size);
		system("cls");
	}
	
}