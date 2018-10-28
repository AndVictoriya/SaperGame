#include "Cell.h"

void Cell::BombBesideCell()														// ”станавливает массив указатель на соседние клетки
{
	for (int i = 0; i < 8; i++)
		if (CellAround[i] != NULL && CellAround[i]->ContentCell != BOMB_CELL)
			CellAround[i]->ContentCell++;
}

void Cell::CreateStack(int & VisibleCell)
{
	stack<Cell *> st;
	st.push(this);
	FindingAnEmptyArea(st, VisibleCell);
}

void Cell::FindingAnEmptyArea(stack<Cell *> & St, int & VisibleCell)			// Ќаходит пустую область с количеством бомб по периметру
{
	while (!St.empty())
	{
		Visible = true;
		for (int i = 0; i < 8; i++)
		{
			if (CellAround[i] != NULL && CellAround[i]->Visible == false && ContentCell == CHAR_NULL)
			{
				CellAround[i]->Visible = true;
				VisibleCell++;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (CellAround[i] != NULL && CellAround[i]->ContentCell == CHAR_NULL)
			{
				for (int j = 0; j < 8; j++)
				{
					if (CellAround[i]->CellAround[j] != NULL && CellAround[i]->CellAround[j]->Visible == false && CellAround[i]->CellAround[j]->ContentCell >= CHAR_NULL)
					{
						St.push(CellAround[i]);
						CellAround[i]->FindingAnEmptyArea(St, VisibleCell);

					}
				}
			}
		}

		if (!St.empty())
		{
			Cell * a = St.top();
			St.pop();
			a->FindingAnEmptyArea(St, VisibleCell);
		}
	}
}
