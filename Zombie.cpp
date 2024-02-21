#include "Zombie.h"

Zombie::Zombie()
{
	hp = 10;
	damage = 3;
	x = 7, y = 7;
}

void Zombie::Draw()
{
	if (hp > 0)
	{
		gotoxy(x * 2, y);
		cout << "Z";
	}
}
