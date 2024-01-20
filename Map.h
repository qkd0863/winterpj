#pragma once
#include "Object.h"
#include "setting.h"


struct Dungeonlocation
{
	int r1, c1, r2, c2;
	int r3, c3, r4, c4;
};


class Map :public Object
{
private:
	int seed = 0;
	char map[Map_y][Map_x];
public:
	Map();
	virtual void Draw();
	virtual void Update();
	Dungeonlocation divideDungeon(int depth, int r1, int c1, int r2, int c2);
};




