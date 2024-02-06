#include "Melee.h"

Melee::Melee()
{
	damage = 10;
	speed = 0.08;
	isAttacking = false;
}

double Melee::get_speed()
{
	return this->speed;
}

void Melee::Shot(int _x, int _y, int _dir)
{
	if (isAttacking == false)  // �������� �ƴ϶��
	{
		switch (_dir)
		{
		case static_cast<int>(Pdir::RIGHT):
			bt.emplace_back(_x + 1, _y, 0, 0, speed);
			bt.emplace_back(_x + 2, _y - 1, 0, 1, speed);
			break;
		case static_cast<int>(Pdir::UP):
			bt.emplace_back(_x, _y - 1, 0, 0, speed);
			bt.emplace_back(_x - 1, _y - 2, 1, 0, speed);
			break;
		case static_cast<int>(Pdir::LEFT):
			bt.emplace_back(_x - 1, _y, 0, 0, speed);
			bt.emplace_back(_x - 2, _y + 1, 0, -1, speed);
			break;
		case static_cast<int>(Pdir::DOWN):
			bt.emplace_back(_x, _y + 1, 0, 0, speed);
			bt.emplace_back(_x + 1, _y + 2, -1, 0, speed);
			break;
		}
		isAttacking = true;
	}
}

void Melee::DrawBullets()
{
	for (auto& bullet : this->bt) {
		bullet.Draw();
	}
}


void Melee::UpdateBullets()
{
	for (auto it = bt.begin(); it != bt.end();)
	{
		it->Update();
		if (it->getCount())
		{
			gotoxy(it->getX() * 2, it->getY());

			if (arr[it->getY()][it->getX()] == 0)
			{
				cout << "+";
			}
			else
			{
				cout << " ";
			}
			it = bt.erase(it);
		}
		else
		{
			it->Update();
			++it;
		}
	}
	if (bt.empty())
	{
		isAttacking = false;
	}
}
