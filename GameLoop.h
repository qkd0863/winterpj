#pragma once
#include "Player.h"
#include "Monster.h"
#include "Map.h"
#include "Object.h"
#include "Timer.h"
#include "Bomb.h"


class GameLoop
{
private:
	//Object* O[100];
	vector<Object*> O;
public:
	GameLoop();
	void AddObject(Player *_P);
	void AddObject(Map *_M);
	void AddObject(Monster *_M);
	void AddObject(Timer *_T);
	void AddObject(Bomb*_I);
	void DeleteObject(Bomb* _I);
	void Draw();
	void Update();
};

