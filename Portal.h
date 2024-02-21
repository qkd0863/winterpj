#pragma once
#include "Object.h"
#include "setting.h"

class Portal :public Object
{
public:
	Portal(int _x, int _y);
	virtual int getX() { return x; };
	virtual int getY() { return y; };
	virtual void Draw();
	virtual void Update();
};

