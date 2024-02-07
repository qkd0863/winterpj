#pragma once
#include "Weapon.h"
class Energyvolt :public Weapon
{
private:
public:
	Energyvolt();
	double get_speed() override;
	void Shot(int _x, int _y, int _dir) override;
};

