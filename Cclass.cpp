#include "Cclass.h"

Cclass::Cclass()
{
	weapon = nullptr;
	isSkill = false;
}

Cclass::~Cclass()
{
	delete weapon;
}
