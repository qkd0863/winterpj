#pragma once
#include "Object.h"
#include "setting.h"
class Barrier :public Object
{
private:
public:
	Barrier(int _x, int _y);
	virtual int getX() { return x; };
	virtual int getY() { return y; };
	virtual void Draw();
	virtual void Update();
	void Activate();
};

