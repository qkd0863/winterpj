#pragma once
#include "Monster.h"

class Dragon : public Monster
{
public:
	Dragon();
	void Draw() override;
	void Update() override;
	void DrawSpace() override;
	void Attack() override;
private:
	int BreathY;
	double TBreath;
	bool IsAttack;
	bool IsBreath;
};

