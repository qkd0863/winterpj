#include "Bomb.h"
#include "setting.h"


Bomb::Bomb(int _x,int _y)
{
	x = _x, y = _y;
	Active = false;
	objectType = BOMB;
}

void Bomb::Draw()
{
	gotoxy(x * 2, y);
	cout << "B";
}

void Bomb::Update()
{
	Cnt.Update();
	if (Cnt.getShowtime() >= 3)
	{
		setDel(true);
		Explosion();
	}
		
}

void Bomb::Explosion()
{
	for (int i = -2;i < 3;i++)
	{
		for (int j = -2;j < 3;j++)
		{
			gotoxy((x + i) * 2, y + j);
			cout << " ";
		}
	}
	
	for (int i = -2;i < 3;i++)
	{
		for (int j = -2;j < 3;j++)
		{
			arr[y + j][x + i] = 1;
		}
	}
}

