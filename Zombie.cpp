#include "Zombie.h"

Zombie::Zombie(int _x, int _y)
{
	hp = 10;
	damage = 3;
	x = _x, y = _y;
}

void Zombie::Draw()
{
	if (hp > 0)
	{
		gotoxy(x * 2, y);
		cout << "Z";
	}
}
