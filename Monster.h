#pragma once
#include "Object.h"
#include "Timer.h"

class Monster :public Object
{
protected:
	int damage;
	double turn = 0;
	Timer Cnt;
public:
	Monster();
	int getX();
	int getY();
	void setX(int _x);
	void setY(int _y);
	virtual void DrawSpace();
	virtual void Draw();
	virtual void Update();
	virtual int getDamage();
	virtual void Attack();
};

