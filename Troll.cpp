#include "Troll.h"

Troll::Troll()
{
	hp = 5;
	damage = 7;
}

void Troll::Draw()
{
	if (hp > 0)
	{
		gotoxy(x * 2, y);
		cout << "T";
	}
}
