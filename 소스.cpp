#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "Player.h"
#include "Monster.h"
#include "setting.h"
#include "Map.h"
#include "GameLoop.h"
#include "Timer.h"




int main()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	GameLoop G;
	Player P;
	Monster MS;
	Map M;
	Timer T;

	clock_t starttime = 0, endtime = 0;
	clock_t time = 0;

	G.AddObject(&T);

	
	G.AddObject(&M);
	G.AddObject(&MS);
	G.AddObject(&P);

	system("mode con:cols=200 lines=60");
	while (1)
	{
		G.Draw();
		G.Update();
	}

}




