#pragma once
#include "Cclass.h"
#include "Melee.h"
#include "Shield.h"

class Knight :public Cclass
{
private:
	double count;
	Shield* shield; // �⺻���� -> Melee, ��ų -> shield
public:
	Knight();
	~Knight();
	void Draw_BT() override;
	void Update_BT() override;
	void Skill(int _x, int _y, int _dir) override;
};

