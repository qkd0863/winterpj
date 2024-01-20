#pragma once
#include <Windows.h>
#include "Object.h"
class Timer :public Object
{
private:
	LARGE_INTEGER periodFrequency;
	LARGE_INTEGER lastTime;
	LARGE_INTEGER curTime;
	double deltaTime;
	double showTime = 0;
	float count = 0;
public:
	Timer();
	double getDelta();
	virtual void Draw();
	virtual void Update();
};

