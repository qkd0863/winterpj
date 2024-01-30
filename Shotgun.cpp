#include "Shotgun.h"

Shotgun::Shotgun()
{
	damage = 4;							   //¼¦°Ç 
	speed = 0.4;	
	bt = std::vector<Bullet>();//¼¦°Ç 
}

double Shotgun::get_speed()
{
	return this->speed;
}

void Shotgun::Shot(int _x, int _y, int _dir)
{
	switch (_dir)
	{
	case static_cast<int>(Pdir::RIGHT):
		bt.emplace_back(_x + 1, _y, 1, 0, speed);
		bt.emplace_back(_x + 1, _y, 1, 1, speed);
		bt.emplace_back(_x + 1, _y, 1, -1, speed);
		break;
	case static_cast<int>(Pdir::UP):
		bt.emplace_back(_x, _y - 1, 0, -1, speed);	
		bt.emplace_back(_x, _y - 1, 1, -1, speed);	
		bt.emplace_back(_x, _y - 1, -1, -1, speed); 
		break;
	case static_cast<int>(Pdir::LEFT):
		bt.emplace_back(_x - 1, _y, -1, 0, speed);
		bt.emplace_back(_x - 1, _y, -1, -1, speed);
		bt.emplace_back(_x - 1, _y, -1, 1, speed);
		break;
	case static_cast<int>(Pdir::DOWN):
		bt.emplace_back(_x, _y + 1, 0, 1, speed);
		bt.emplace_back(_x, _y + 1, -1, 1, speed);
		bt.emplace_back(_x, _y + 1, 1, 1,speed);
		break;
	}
}
