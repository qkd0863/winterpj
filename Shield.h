#pragma once
#include "Weapon.h"

class Shield : public Weapon // ½¯µå
{
private:
public:
	Shield();
	double get_speed() override;
	void Shot(int _x, int _y, int _dir) override;
	void DrawBullets() override;
	void UpdateBullets() override;
};
