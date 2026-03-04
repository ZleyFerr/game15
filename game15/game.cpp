#include "game.h"

int gameFieldSize = 4;

void loadGame()
{
	createField(gameFieldSize);
}

void renderGame()
{
	printField(gameFieldSize);
}

void playGame()
{
	loadGame();

	while (!checkWin())
	{
		renderGame();
		changeCells(gameFieldSize);
		checkWin();
	}
	if (checkWin)
	{
		renderGame();
		std::cout << "Победа!\n";
	}
}
