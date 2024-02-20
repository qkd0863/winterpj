#include "DeleteHurdle.h"

DeleteHurdle::DeleteHurdle(int _x, int _y)
{
	x = _x, y = _y;
	objectType = DELETEHURDLE;
}

void DeleteHurdle::Draw()
{
	gotoxy(x * 2, y);
	cout << "¢Ã";
}

void DeleteHurdle::Update()
{

}

void DeleteHurdle::Activate()
{
	setDel(true);

	for (int i = 0;i < SIZE_ARR_X;i++)
	{
		for (int j = 0;j < SIZE_ARR_Y;j++)
		{
			if (arr[j][i] == 1)
				arr[j][i] = 3;
		}
	}

	for (int i = 0;i < SIZE_ARR_X;i++)
	{
		for (int j = 0;j < SIZE_ARR_Y;j++)
		{
			if (arr[j][i] == 1)
			{
				gotoxy(i * 2, j);
				cout << ' ';
			}
		}
	}
}
