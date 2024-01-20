#include "Monster.h"
#include <time.h>
#include <stdlib.h>

#include "setting.h"


Monster::Monster()
{
	srand((unsigned int)time(NULL));

	x = rand() % 3 + 2;
	y = rand() % 3 + 6;
}

int Monster::getX()
{
	return x;
}
int Monster::getY()
{
	return y;
}
void Monster::setX(int _x)
{
	x = _x;
}
void Monster::setY(int _y)
{
	y = _y;
}

void Monster::DrawSpace()
{
	gotoxy(x * 2, y);
	cout << " ";
}



void Monster::Draw()
{
	gotoxy(x * 2, y);
	cout << "M";
}

void Monster::Update()
{
	Cnt.Update();
	turn += Cnt.getDelta();

	if (turn >= 1)
	{
		DrawSpace();

		int action = rand() % 4;
		switch (action)
		{
		case 0:
			if (x < 9)
			{
				x++;
				gotoxy(0, 20);
				cout << "                              ";
				gotoxy(0, 20);
				
			}			
			break;
		case 1:
			if (x > 1)
			{
				x--;
				gotoxy(0, 20);
				cout << "                              ";
				gotoxy(0, 20);
				
			}
			break;
		case 2:
			if (y < 9)
			{
				y++;
				gotoxy(0, 20);
				cout << "                              ";
				gotoxy(0, 20);
				
			}		
			break;
		case 3:
			if (y > 1)
			{
				y--;
				gotoxy(0, 20);
				cout << "                              ";
				gotoxy(0, 20);
				
			}
			break;
		default:
			break;
		}
	
		turn = 0;
	}	
}