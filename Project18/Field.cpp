#include "Field.h"


Field::Field()
{
	cout << "Enter size field:" << endl;
	cin >> SizeCell;
	cout << endl;
	cout << "Enter number of bombs:" << endl;
	cin >> Bomb;
	cout << endl;

	GameField = new Cell* [SizeCell];										// ������� ������ ��� ������� ����
	for (int i = 0; i < SizeCell; i++)
		GameField[i] = new Cell[SizeCell];
}

void Field::ReferenceOnCell()												// �������� ������ �� ������			 
{
	for (int i = 0; i < SizeCell; i++)
		for (int j = 0; j < SizeCell; j++)
			CellsAround(GameField[i][j], i, j);
}

void Field::CellsAround(Cell & �entral�ell, const int i, const int j)		// �������� ������ �� �������� ������
{
	int mas_i[] = { i, i - 1, i - 1, i - 1, i, i + 1, i + 1, i + 1 };
	int mas_j[] = { j - 1, j - 1, j, j + 1, j + 1, j + 1, j, j - 1 };

	for (int counter = 0; counter < 8; counter++)
		if (NoNull(mas_i[counter], mas_j[counter]))
			�entral�ell.SetPointer(GameField[mas_i[counter]][mas_j[counter]], counter);

}

void Field::RandBomb()														// ������������� ����� �� ������� ����
{
	srand((unsigned)time(NULL));
	int a = 0;
	while (a < Bomb)
	{
		int i = (1 + rand() % SizeCell);
		int j = (1 + rand() % SizeCell);

		if (NoBomb(i - 1, j - 1))
		{
			GameField[i - 1][j - 1].GetCell() = BOMB;			
			a++;
		}
	}
}

void Field::BombInCell() 													// ����� ���� ����
{
	for (int i = 0; i < SizeCell; i++)
		for (int j = 0; j < SizeCell; j++)
			if (GameField[i][j].GetCell() == BOMB)
				GameField[i][j].BombBesideCell();
}

bool Field::NoNull(const int a, const int b) const							// �������� �� ����� �� ������� ����
{
	if (a < 0 || b < 0 || a > SizeCell-1 || b > SizeCell-1)
		return false;
	else
		return true;
}

bool Field::NoBomb(const int a, const int b) const							// �������� �� ������� � ������ �����
{
	if (GameField[a][b].GetCell() == BOMB)
		return false;
	else
		return true;
}

void Field::Options()														// ����� ������������
{
	while (Status == 0)
	{

		int a, b;
		cout << "Enter coordinates: " << endl;
		cin >> a >> b;

		if (GameField[a - 1][b - 1].GetVisible() == 0)
		{
			switch (GameField[a - 1][b - 1].GetCell())
			{
			case BOMB:
				cout << "You lose!" << endl;
				Status = 1;
				break;
			case (char)48:
				VisibleCell++;
				GameField[a - 1][b - 1].CreateStack(VisibleCell);
				PrintField();

				break;
			default:
				GameField[a - 1][b - 1].SetVisible();
				PrintField();
				VisibleCell++;
				break;
			}

			if (VisibleCell == SizeCell * SizeCell - Bomb)
			{
				cout << "You Win!!!" << endl;
				Status = 1;
			}
		}
	}
}

void Field::PrintField() 															
{
	system("cls");

	if (SizeCell > 9)
	{
		cout << "                     ";
		for (int i = 10; i <= SizeCell; i++)
			cout << i / 10 << ' ';
	}
	cout << endl<<"   ";

	for (int i = 1; i <= SizeCell; i++)
		cout << i % 10<<' ';
	cout << endl;

	for (int i = 0; i < SizeCell; i++)
	{
		cout << "  ";
		for (int a = 0; a < SizeCell; a++)
			cout << " " << CH1;
		cout << endl ;

		if (i <9)
			cout << ' ';
		cout << i + 1;

		for (int j = 0; j < SizeCell; j++)
		{
			cout << CH2;
			if (GameField[i][j].GetVisible() == true)
				(GameField[i][j].GetCell() == (char)48) ? cout << (char)35 : cout << GameField[i][j].GetCell();   // 48 - '0' 35 -'#'
			else
				cout << ' ';
		}
		cout << CH2 << endl;
	}
	cout << "  ";

	for (int a = 1; a <= SizeCell; a++)
		cout << " " << CH1;
	cout << endl;
}

Field::~Field()
{
	for (int i = 0; i < SizeCell; i++)
	{
		delete [] GameField[i];
	}
	delete[] GameField;
}



