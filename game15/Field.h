#pragma once
#include "FieldCell.h"
#include <vector>
#include <random>
#include <set>

void createField(unsigned short int size);
void printField(int size);
void updateFieldCellsStatuses(int size);
void changeCells(int size);
bool isMoveAvaiable(FieldCell& cell);
int getCellIndex(int value);
bool checkWin();