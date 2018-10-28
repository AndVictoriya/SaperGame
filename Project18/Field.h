#pragma once
#include "Cell.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define BOMB (char) 42		// 42 - '*'
#define CH1 (char) 45		// 45 - '_'
#define CH2 (char) 179		// 179 - '|'

class Field
{
public:
	Field();
	void ReferenceOnCell();
	void CellsAround(Cell &, const int, const int);
	void RandBomb();
	void BombInCell();
	bool NoNull(const int, const int) const;
	bool NoBomb(const int,const int) const;
	void Options();
	void PrintField();
	~Field();
private:
	bool Status = 0;		// 0 - игра продолжается, 1 - игра окончена 
	int VisibleCell = 0;	// количество видимых клеток пользовотелю
	Cell ** GameField;		// игровое поле
	int Bomb;				// кол-во бомб на поле
	int SizeCell;			// размер поля
};

