#include "Melee.h"

Melee::Melee()
{
	damage = 10;
	speed = 1.0;
}

double Melee::get_speed()
{
	return this->speed;
}

void Melee::Shot(int _x, int _y, int _dir)
{
	bt.emplace_back(0, 0, 0, 1, 0.3);	// 피스톨
	bt.emplace_back(0, 0, 0, 1, 0.3);	// 피스톨
}

void Melee::UpdateBullets()
{
}
