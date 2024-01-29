#pragma once
#include "Weapon.h"

class Shield : public Weapon // ½¯µå
{
private:
	int damage;
	double speed;
public:
	Shield();
	double get_speed() override;
	void Shot(int _x, int _y, int _dir) override;
	void UpdateBullets() override;
};
