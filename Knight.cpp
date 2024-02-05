#include "Knight.h"

Knight::Knight()
{
	count = 0;
	shield = new Shield();
	weapon = new Melee();
	isSkill = false;
}

Knight::~Knight()
{
	delete shield;
	delete weapon;
}

void Knight::Draw_BT()
{
	weapon->DrawBullets();
	if (isSkill == true)
		shield->DrawBullets();
}

void Knight::Update_BT()
{
	weapon->UpdateBullets();
	if (isSkill == true) 
	{
		shield->UpdateBullets();
		if (shield->bt.empty())
		{
			isSkill = false;
		}
	}

}

void Knight::Skill(int _x, int _y, int _dir)
{
	isSkill = true;
	shield->Shot(_x, _y, _dir);
}
