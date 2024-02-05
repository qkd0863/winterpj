#include "Bullet.h"

void Bullet::Update()
{
	Cnt.Update();
	speed += Cnt.getDelta();
	MeleeCnt += Cnt.getDelta();
	if (speed > wp_speed)
	{
		gotoxy(x * 2, y);  // 더블 버퍼링할 땐 삭제
		cout << " ";	// 더블 버퍼링할 땐 삭제
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
	gotoxy(x * 2, y);
	cout << "☆";
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


