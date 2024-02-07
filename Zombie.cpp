#include "Zombie.h"

Zombie::Zombie()
{
	hp = 10;
	damage = 3;
}

void Zombie::Draw()
{
	if (hp > 0)
	{
		gotoxy(x * 2, y);
		cout << "Z";
	}
}
