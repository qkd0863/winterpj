#include "Weapon.h"

Weapon::Weapon()
{
}

double Weapon::get_speed()
{
	return 0.0;
}

void Weapon::Shot()
{

}



Pistol::Pistol()
{
	damage = 5;						// ÇÇ½ºÅç
	speed = 0.3;						// ÇÇ½ºÅç
	bt.emplace_back(0, 0, 1, 0, speed);	// ÇÇ½ºÅç
}

double Pistol::get_speed()
{
	return this->speed;
}

void Pistol::Shot()
{
	bt.emplace_back(0, 0, 1, 0, 0.3);	// ÇÇ½ºÅç
}

Shotgun::Shotgun()
{
	damage = 4;							   //¼¦°Ç 
	speed = 0.4;						   //¼¦°Ç 
	bt.emplace_back(0, 0, 1, 0, speed);	   //¼¦°Ç 
	bt.emplace_back(0, 0, 1, 1, speed);	   //¼¦°Ç 
	bt.emplace_back(0, 0, 1, -1, speed);   //¼¦°Ç 
}

double Shotgun::get_speed()
{
	return this->speed;
}

void Shotgun::Shot()
{
	bt.emplace_back(0, 0, 1, 0, speed);	   //¼¦°Ç 
	bt.emplace_back(0, 0, 1, 1, speed);	   //¼¦°Ç 
	bt.emplace_back(0, 0, 1, -1, speed);   //¼¦°Ç 
}
