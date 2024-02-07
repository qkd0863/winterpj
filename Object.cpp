#include "Object.h"

void Object::Draw()
{
}

void Object::Update()
{
}

int Object::getX()
{
	return x;
}

int Object::getY()
{
	return y;
}

int Object::getHP()
{
	return hp;
}

void Object::calculateDamage(int damage)
{
	hp -= damage;
}
