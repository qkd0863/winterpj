#pragma once
#include "Cclass.h"
class Magician : public Cclass
{
private:
public:
	void Draw_BT() override;
	void Skill(int _x, int _y, int _dir) override;
};

