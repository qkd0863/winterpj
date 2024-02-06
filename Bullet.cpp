#include "Bullet.h"

void Bullet::Update()
{
	Cnt.Update();
	speed += Cnt.getDelta();
	MeleeCnt += Cnt.getDelta();
	if (speed > wp_speed)
	{
		x += dx;
		y += dy;
		speed = speed - wp_speed;
	}
}

Bullet::Bullet(int _x, int _y, int _dx, int _dy, double _speed)
{
	x = _x;
	y = _y;
	dx = _dx;
	dy = _dy;
	wp_speed = _speed;
	speed = 0;
	MeleeCnt = 0;
}

int Bullet::getDX()
{
	return dx;
}

int Bullet::getDY()
{
	return dy;
}

int Bullet::getX()
{
	return x;
}

int Bullet::getY()
{
	return y;
}

void Bullet::Draw()
{
	gotoxy((x-dx) * 2, (y - dy));
	if (arr[y - dy][x - dx] == 0)
		cout << "+";
	else
		cout << " ";
	gotoxy(x * 2, y);
	if (arr[y][x] == 0)
		cout << "+";
	else
		cout << "¡Ù";
	
}

bool Bullet::getCount()
{
	if (MeleeCnt >= 3 * wp_speed) 
	{
		return true;
	}
	else {
		return false;
	}
}


