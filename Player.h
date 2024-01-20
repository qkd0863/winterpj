#pragma once
#include "Object.h"
#include "Timer.h"

class Player :public Object
{

	
private:
	int x = 5;int y = 5;
	int atkx = 0, atky = 0;
	double count = 0;
	Timer Cnt;
public:
	int getX();
	int getY();
	void setX(int _x);
	void setY(int _y);
	void action();
	void attack();
	void DrawSpace(int x, int y);
	virtual void Draw();
	virtual void Update();
	void KeyEvent(int input);
};
