#pragma once
#include "Weapon.h"

class Shotgun : public Weapon
{
private:
	int damage;
	double speed;
public:
	Shotgun();
	double get_speed() override;
	void Shot(int _x, int _y, int _dir) override;
};

