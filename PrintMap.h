#pragma once
#include "setting.h"

void PrintMap()
{
	for (int i = 0; i < SIZE_ARR_Y; i++)
	{
		for (int j = 0; j < SIZE_ARR_X; j++)
		{
			gotoxy(j * 2, i);
			switch (arr[i][j])
			{
			case 0:
				cout << '+';
				break;
			case 1:
				cout << 'X';
				break;
			default:
				//printf("%d", arr[i][j]);
				cout << ' ';
				break;
			}
		}
	}
}