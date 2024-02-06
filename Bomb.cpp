#include "Bomb.h"
#include "setting.h"


Bomb::Bomb()
{
	x = rand() % 60, y = rand() % 60;
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
}

