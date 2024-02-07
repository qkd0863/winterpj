#include "Map.h"
#include "setting.h"


Map::Map()
{
	objectType = MAP;
}	

void Map::AddObject(Player* _P)
{
	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
	{
		if (O[i] == nullptr)
		{
			O[i] = _P;
			break;
		}
	}
}


void Map::AddObject(Monster* _M)
{
	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
	{
		if (O[i] == nullptr)
		{
			O[i] = _M;
			break;
		}
	}
}

void Map::Draw()
{
	if (draw)
	{
		for (int i = 0;i < SIZE_ARR_Y;i++)
		{
			for (int j = 0;j < SIZE_ARR_X;j++)
			{
				gotoxy(j * 2, i);
			
				
			}
		}
	}
	
	draw = false;
}

void Map::Update()
{


}

const char(*Map::GetMapArray())[Map_x]{
	return map;
}