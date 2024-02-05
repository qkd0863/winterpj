#include "Shield.h"

Shield::Shield()
{
	damage = 5;
	speed = 0.6;
}

double Shield::get_speed()
{
	return this->speed;
}

void Shield::Shot(int _x, int _y, int _dir)
{
	bt.emplace_back(_x, _y - 1, 0, 0, speed);
	bt.emplace_back(_x + 1, _y - 1, 0, 0, speed);
	bt.emplace_back(_x - 1, _y - 1, 0, 0, speed);
	bt.emplace_back(_x + 1, _y, 0, 0, speed);
	bt.emplace_back(_x - 1, _y, 0, 0, speed);
	bt.emplace_back(_x + 1, _y + 1, 0, 0, speed);
	bt.emplace_back(_x, _y + 1, 0, 0, speed);
	bt.emplace_back(_x - 1, _y + 1, 0, 0, speed);
}

void Shield::DrawBullets()
{
	for (auto& bullet : this->bt) {
		bullet.Draw();
	}
}

void Shield::UpdateBullets()
{
	for (auto it = bt.begin(); it != bt.end();)
	{
		if (it->getCount())
		{
			gotoxy(it->getX() * 2, it->getY());
			cout << " ";
			it = bt.erase(it);
		}
		else
		{
			it->Update();
			++it;
		}
	}
}

