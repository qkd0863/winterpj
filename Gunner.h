#pragma once
#include "Cclass.h"
#include "Pistol.h"
#include "Shotgun.h"
class Gunner :public Cclass
{
private:
public:
	Gunner();
	~Gunner();
	void setWeapon() override;
    void Draw_BT() override;
	void attack(int _x, int _y, int _dir) override;
	void Skill(int _x, int _y, int _dir) override;
};

