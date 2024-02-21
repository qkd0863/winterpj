#include "setting.h"


void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void PrintProgrees()
{
	int y = 25;

	gotoxy(70 * 2, y);
	cout << '1';
	gotoxy(70 * 2, y-1);
	cout << 'l';
	gotoxy(70 * 2, y-2);
	cout << '2';
	gotoxy(70 * 2, y-3);
	cout << 'l';
	gotoxy(70 * 2, y-4);
	cout << '3';
	gotoxy(70 * 2, y-5);
	cout << 'l';
	gotoxy(70 * 2, y-6);
	cout << "Boss";
	gotoxy(70 * 2, y-7);
	

	switch (roomcnt)
	{
	case 0:
		gotoxy(70 * 2, y);
		cout << 'P';
		break;
	case 1:
		gotoxy(70 * 2, y-2);
		cout << 'P';
		break;
	case 2:
		gotoxy(70 * 2, y-4);
		cout << 'P';
		break;
	case 3:
		gotoxy(70 * 2, y-6);
		cout << "       ";
		gotoxy(70 * 2, y-6);
		cout << 'P';
		break;
	default:
		break;
	}


}