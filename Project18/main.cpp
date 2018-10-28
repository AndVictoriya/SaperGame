using namespace std;
#include "Field.h"

int main()
{
	Field a;
	a.ReferenceOnCell();
	a.RandBomb();
	a.BombInCell();
	a.PrintField();
	a.Options();
	system("pause");
	return 0;
}