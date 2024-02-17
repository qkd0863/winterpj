#pragma once
#include "Object.h"
#include "setting.h"


class MapNode
{
public:
	int map[SIZE_ARR_X][SIZE_ARR_Y];
	class MapNode* ptr;
};


class MapMgr :public Object
{
private:
	MapNode* head;
public:
	MapMgr();
	void ChageMap();
	void MakeMap();

};
