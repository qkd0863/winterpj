#pragma once
#include <iostream>
#include "Object.h"
#include "setting.h"
#include "Timer.h"

class Bullet : public Object
{
private:
	int x; int y;
	int dx; int dy;
	double speed;
	double wp_speed;
	Timer Cnt;
public:
	Bullet(int _x, int _y, int _dx, int _dy, double _speed);
	int getDX();
	int getDY();
	int getX();
	int getY();
	void Update();
	void Draw();
};

