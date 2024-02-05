#pragma once
#include "Weapon.h"
class Energyvolt :public Weapon
{
private:
	int damage;
	double speed;
public:
	Energyvolt();
	double get_speed() override;
	void Shot(int _x, int _y, int _dir) override;
};

