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
	gotoxy(70 * 2, 10);
	cout << '1';
	gotoxy(70 * 2, 9);
	cout << 'l';
	gotoxy(70 * 2, 8);
	cout << '2';
	gotoxy(70 * 2, 7);
	cout << 'l';
	gotoxy(70 * 2, 6);
	cout << '3';
	gotoxy(70 * 2, 5);
	cout << 'l';
	gotoxy(70 * 2, 4);
	cout << "Boss";
	gotoxy(70 * 2, 3);
	

	switch (roomcnt)
	{
	case 0:
		gotoxy(70 * 2, 10);
		cout << 'P';
		break;
	case 1:
		gotoxy(70 * 2, 8);
		cout << 'P';
		break;
	case 2:
		gotoxy(70 * 2, 6);
		cout << 'P';
		break;
	case 3:
		gotoxy(70 * 2, 4);
		cout << "       ";
		gotoxy(70 * 2, 4);
		cout << 'P';
		break;
	default:
		break;
	}


}