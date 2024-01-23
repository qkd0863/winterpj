#include "Weapon.h"

Weapon::Weapon()
{
	//bt.emplace_back(0, 0, 1, 0, 0.3);	// 피스톨
	//damage = 5;						// 피스톨
	//speed = 0.3;						// 피스톨

	damage = 4;							   //샷건 
	speed = 0.4;						   //샷건 
	bt.emplace_back(0, 0, 1, 0, speed);	   //샷건 
	bt.emplace_back(0, 0, 1, 1, speed);	   //샷건 
	bt.emplace_back(0, 0, 1, -1, speed);   //샷건 

	// 추후 무기 종류를 늘려감에 따라 상속으로 뺄 예정
}

double Weapon::get_speed()
{
	return speed;
}

void Weapon::Reload()
{
	bullet_num = MAX_BULLET;
}

//Pistol::Pistol()
//{
//	  bt.emplace_back(0, 0, 1, 0);
//	  int damage = 5;
//}
//
//void Pistol::Reload()
//{
//	  bullet_num = MAX_BULLET;
//}
