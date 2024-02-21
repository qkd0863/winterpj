#pragma once
#include "Monster.h"
class Zombie : public Monster
{
public:
	Zombie(int _x, int _y);
	void Draw() override;
private:
};

