#pragma once
#include "Weapon.h"

class Pistol : public Weapon
{
private:
	int damage;
	double speed;
public:
	Pistol();
	double get_speed() override;
	void Shot(int _x, int _y, int _dir) override;
};

