#include "Monster.h"
#include <time.h>
#include <stdlib.h>

#include "setting.h"


Monster::Monster()
{

	while (1)
	{
		x = rand() % Map_x;
		y = rand() % Map_y;
		if (arr[y][x] == 0)
		{
			break;
		}
	}
	mx = x;
	my = y;
	hp = 10;
	objectType = MONSTER;
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
	if (hp > 0) 
	{
		gotoxy(x * 2, y);
		cout << " ";
	}
}


void Monster::Draw()
{
	if (hp > 0)
	{
		gotoxy(x * 2, y);
		cout << "M";
	}
	
}

void Monster::Update()
{
	Cnt.Update();
	turn += Cnt.getDelta();

	if (turn >= 1)
	{
		DrawSpace();

		while (1)
		{
			int action = rand() % 4;
			switch (action)
			{
			case 0:
				mx++;
				break;
			case 1:
				mx--;
				break;
			case 2:
				my++;
				break;
			case 3:
				my--;
				break;
			}
			if (arr[my][mx] != 0)
			{
				y = my;
				x = mx;
				break;
			}
			else
			{
				my = y;
				mx = x;
			}
		}
	
		turn -= 1;
	}	
}

int Monster::getDamage()
{
	return damage;
}

void Monster::Attack()
{
	
}
