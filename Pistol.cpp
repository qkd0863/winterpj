#include "Pistol.h"

Pistol::Pistol()
{
	damage = 5;						// 피스톨
	speed = 0.3;						// 피스톨
}

double Pistol::get_speed()
{
	return this->speed;
}

void Pistol::Shot(int _x, int _y, int _dir)
{
	switch (_dir)
	{
	case static_cast<int>(Pdir::RIGHT):
		bt.emplace_back(_x + 1, _y, 1, 0, speed);	// 피스톨
		break;
	case static_cast<int>(Pdir::UP):
		bt.emplace_back(_x, _y - 1, 0, -1, speed);	// 피스톨
		break;
	case static_cast<int>(Pdir::LEFT):
		bt.emplace_back(_x - 1, _y, -1, 0, speed);	// 피스톨
		break;
	case static_cast<int>(Pdir::DOWN):
		bt.emplace_back(_x, _y + 1, 0, 1, speed);	// 피스톨
		break;
	}
}
