#include "Shield.h"

Shield::Shield()
{
	damage = 5;
	speed = 0.3;
}

double Shield::get_speed()
{
	return this->speed;
}

void Shield::Shot(int _x, int _y, int _dir)
{

}

void Shield::UpdateBullets()
{
	for (auto it = bt.begin(); it != bt.end();)
	{
		it->Update();
	}
}

