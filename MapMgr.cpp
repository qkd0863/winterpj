#include "MapMgr.h"

void copymap(MapNode * MN);

MapMgr::MapMgr()
{
	objectType = MAPMGR;
}

void MapMgr::ChageMap()
{
	MapNode* MN = new MapNode;
	copymap(MN);




	MakeMap();
}

void MapMgr::MakeMap()
{
}



void copymap(MapNode* MN)
{
	for (int i = 0;i < SIZE_ARR_X;i++)
	{
		for (int j = 0;j < SIZE_ARR_Y;j++)
		{
			MN->map[j][i] = arr[j][i];
		}
	}
}