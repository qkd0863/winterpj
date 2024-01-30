#pragma once
#include "Object.h"
#include "Bullet.h"
#include <vector>

using namespace std;

namespace Wp_slot
{
	const int FIR = 0;
	const int SEC = 1;
}

class Weapon
{
public:
	Weapon();
	string Wname;
	vector <Bullet> bt;
	virtual double get_speed() = 0;
	virtual void Shot(int _x, int _y, int _dir) = 0;
	enum class Pdir
	{
		RIGHT = 0,
		LEFT = 180,
		UP = 90,
		DOWN = 270
	};
	virtual void DrawBullets() {
		for (auto& bullet : this->bt) {
			bullet.Draw();
		}
	}
	virtual void UpdateBullets()
	{
		for (auto it = bt.begin(); it != bt.end();)
		{
			it->Update();
			if (it->getX() <= 0 || it->getX() >= Map_x || it->getY() <= 0 || it->getY() >= Map_y)
			{
				gotoxy(it->getX() * 2, it->getY());
				cout << " ";
				it = bt.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
};

