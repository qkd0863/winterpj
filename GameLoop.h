#pragma once
#include "Player.h"
#include "Monster.h"
#include "Map.h"
#include "Object.h"
#include "Timer.h"


class GameLoop
{
private:
	Object* O[10];
	Player** SP = nullptr;
	Map** SM = nullptr;
public:
	GameLoop();
	void AddObject(Player *_P);
	void AddObject(Map *_M);
	void AddObject(Monster *_M);
	void AddObject(Timer *_T);
	void Draw();
	void Update();
};

