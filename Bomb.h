#pragma once
#include "Object.h"
#include "setting.h"
#include "Timer.h"

class Bomb :public Object
{
private:
	Timer Cnt;
	BOOL Active;
public:
	
	Bomb(int _x, int _y);
	virtual int getX() { return x; };
	virtual int getY() { return y; };
	virtual void Draw();
	virtual void Update();
	void Explosion();
	BOOL getActive() {return Active;};
	void setActive(BOOL _A) { Active = _A; };

};

