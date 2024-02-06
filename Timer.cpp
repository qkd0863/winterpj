#include "Timer.h"
#include "setting.h"

Timer::Timer()
{
	QueryPerformanceFrequency(&periodFrequency);
	QueryPerformanceCounter(&lastTime);
	objectType = TIMER;
}

void Timer::Draw()
{
	gotoxy(0, 60);
	cout << "                                                                         "; 
	gotoxy(0, 60);
	cout << "deltaTime:" << deltaTime << "\t";
	cout << "Fps:" << 1/deltaTime << "\t";
	cout << "Time:" << int(showTime) << "\t";
	cout << "Bomb == B" << endl;
	
}

void Timer::Update()
{
	QueryPerformanceCounter(&curTime); 
	deltaTime = (double)(curTime.QuadPart - lastTime.QuadPart) / periodFrequency.QuadPart;
	
	
	lastTime = curTime; 
	showTime += deltaTime;
}

double Timer::getDelta()
{
	return deltaTime;
}
