#include "Field.h"

int main()
{
	try
	{
		Field a;
		a.ReferenceOnCell();
		a.RandBomb();
		a.BombInCell();
		a.PrintField();
		a.Options();
	}
	catch (const exception &ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}