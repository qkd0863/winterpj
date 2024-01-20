#include "Timer.h"
#include "setting.h"

Timer::Timer()
{
	QueryPerformanceFrequency(&periodFrequency);
	QueryPerformanceCounter(&lastTime);
}

void Timer::Draw()
{
	gotoxy(0, 55);
	cout << "                                                                         "; 
	gotoxy(0, 55);
	cout << "deltaTime:" << deltaTime << "\t";
	cout << "Fps:" << 1/deltaTime << "\t";
	cout << "Time:" << int(showTime) << endl;
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
