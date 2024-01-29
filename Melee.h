#pragma once
#include "Weapon.h"

class Melee : public Weapon // 근접 공격
{
private:
	int damage;
	double speed;

public:
	Melee();
	double get_speed() override;
	void Shot(int _x, int _y, int _dir) override;
	void UpdateBullets() override;
};

