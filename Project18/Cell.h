#pragma once
#include<iostream>
#include<stack>
using namespace std;

#define BOMB_CELL (char) 42		// 42 - '*'
#define CHAR_NULL (char) 48		// 48 - '0'

class Cell
{
public:
	void SetPointer(Cell & aPtr, int a) { CellAround[a] = &aPtr; };
	void SetVisible() { Visible = 1; };
	char & GetCell() { return ContentCell; };
	bool GetVisible() { return Visible; };
	void BombBesideCell();
	void CreateStack(int &);
	void FindingAnEmptyArea(stack<Cell *> &, int &);
private:
	char ContentCell = CHAR_NULL;			// содержимое клетки
	Cell * CellAround[8] = { NULL };		// массив указателей на соседние €чейки
	bool Visible = 0;						// видима €чейка 0 - нет 1 - да	
};

