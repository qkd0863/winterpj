#pragma once
#include "Object.h"
#include "setting.h"
#include "Player.h"
#include "Monster.h"

struct Dungeonlocation
{
	int r1, c1, r2, c2;
	int r3, c3, r4, c4;
};


class Map :public Object
{
private:
	BOOL draw;
	char map[Map_y][Map_x];
	Object* O[10];
public:
	Map();
	virtual void Draw();
	virtual void Update();
	Dungeonlocation divideDungeon(int depth, int r1, int c1, int r2, int c2);

	void AddObject(Player* _P);
	void AddObject(Monster* _M);
};




