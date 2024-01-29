#include "Gunner.h"

Gunner::Gunner()
{
	weapon = new Shotgun();
	wname = "Shotgun";
}

Gunner::~Gunner()
{
	delete weapon;
}

void Gunner::setWeapon()
{
	if (wname == "Pistol")
	{
		delete weapon;
		weapon = new Shotgun();
		wname = "Shotgun";
	}
	else if (wname == "Shotgun")
	{
		delete weapon;
		weapon = new Pistol();
		wname = "Pistol";
	}
}

void Gunner::attack(int _x, int _y, int _dir)
{
	weapon->Shot(_x, _y, _dir);
}
