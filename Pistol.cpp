#include "Pistol.h"

Pistol::Pistol()
{
	damage = 5;						// �ǽ���
	speed = 0.3;						// �ǽ���
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
		bt.emplace_back(_x + 1, _y, 1, 0, speed);	// �ǽ���
		break;
	case static_cast<int>(Pdir::UP):
		bt.emplace_back(_x, _y - 1, 0, -1, speed);	// �ǽ���
		break;
	case static_cast<int>(Pdir::LEFT):
		bt.emplace_back(_x - 1, _y, -1, 0, speed);	// �ǽ���
		break;
	case static_cast<int>(Pdir::DOWN):
		bt.emplace_back(_x, _y + 1, 0, 1, speed);	// �ǽ���
		break;
	}
}
