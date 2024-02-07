#pragma once
#include "Weapon.h"

class Melee : public Weapon // ���� ����
{
private:
	bool isAttacking;
public:
	Melee();
	double get_speed() override;
	void Shot(int _x, int _y, int _dir) override;
	void DrawBullets() override;
	void UpdateBullets() override;
};

