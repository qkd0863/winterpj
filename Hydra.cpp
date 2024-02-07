#include "Hydra.h"

Hydra::Hydra()
{
	hp = 8;
	damage = 5;
}

void Hydra::Draw()
{
	if (hp > 0)
	{
		gotoxy(x * 2, y);
		cout << "H";
	}
}
