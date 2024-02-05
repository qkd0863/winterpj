#pragma once
#include "Object.h"
#include "setting.h"
#include "Timer.h"

class Bomb :public Object
{
private:
	int x = rand()%40, y = rand() % 40;
	Timer Cnt;
	BOOL Active = false;
public:
	

	virtual int getX() { return x; };
	virtual int getY() { return y; };
	virtual void Draw();
	virtual void Update();
	void Explosion();
	BOOL getActive() {return Active;};
	void setActive(BOOL _A) { Active = _A; };

};
