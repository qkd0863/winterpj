#include "Cclass.h"

Cclass::Cclass()
{
	weapon = nullptr;
}

Cclass::~Cclass()
{
	delete weapon;
}
