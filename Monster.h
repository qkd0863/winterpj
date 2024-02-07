#pragma once
#include "Object.h"
#include "Timer.h"

class Monster :public Object
{
protected:
	double turn = 0;
	Timer Cnt;
public:
	Monster();
	int getX();
	int getY();
	void setX(int _x);
	void setY(int _y);
	void DrawSpace();
	virtual void Draw();
	virtual void Update();
};

