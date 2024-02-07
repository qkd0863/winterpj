#pragma once
#include "Weapon.h"

class Pistol : public Weapon
{
private:
public:
	Pistol();
	double get_speed() override;
	void Shot(int _x, int _y, int _dir) override;
};

