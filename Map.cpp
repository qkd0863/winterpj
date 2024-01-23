#include "Map.h"
#include "setting.h"

Map::Map()
{
	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
	{
		O[i] = nullptr;
	}

	for (int i = 0;i < Map_y;i++)
	{
		for (int j = 0;j < Map_x;j++)
		{
			map[j][i] = '+';
		}
	}
	divideDungeon(2, 0, 0, Map_x, Map_y);
	draw = true;
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
		for (int i = 0;i < Map_x;i++)
		{
			for (int j = 0;j < Map_y;j++)
			{
				gotoxy(j * 2, i);
				cout << map[j][i];
			}
		}
	}
	
	draw = false;
}

void Map::Update()
{


}

Dungeonlocation Map::divideDungeon(int depth, int r1, int c1, int r2, int c2)
{
	Dungeonlocation location;

	if (depth == 0 || (r2 - r1 <= 10 || c2 - c1 <= 10))
	{
		for (int i = r1 + 2;i < r2 - 2;i++)
		{
			for (int j = c1 + 2;j < c2 - 2;j++)
			{
				map[i][j] = ' ';
			}
		}

		return { r1 + 2,c1 + 2,r2 - 3,c2 - 3,r1 + 2,c1 + 2,r2 - 3,c2 - 3 };
	}


	int rLen = r2 - r1;
	int cLen = c2 - c1;
	Dungeonlocation temp1, temp2;

	if (rLen / cLen > 1 || (cLen / rLen <= 1 && rand() % 2))
	{
		int divideNum = (r2 - r1) * (rand() % 3 + 4) / 10;

		//방 분할
		temp1 = divideDungeon(depth - 1, r1, c1, r1 + divideNum, c2);
		temp2 = divideDungeon(depth - 1, r1 + divideNum, c1, r2, c2);


		//방 합치기
		map[temp1.r4 + 1][(temp1.c3 + temp1.c4) / 2] = ' ';
		map[temp1.r4 + 2][(temp1.c3 + temp1.c4) / 2] = ' ';
		map[temp2.r1 - 1][(temp2.c1 + temp2.c2) / 2] = ' ';
		map[temp2.r1 - 2][(temp2.c1 + temp2.c2) / 2] = ' ';

		int rmin = min((temp1.c3 + temp1.c4) / 2, (temp2.c1 + temp2.c2) / 2);
		int rmax = max((temp1.c3 + temp1.c4) / 2, (temp2.c1 + temp2.c2) / 2);

		for (int i = rmin;i <= rmax;i++)
		{
			map[temp2.r1 - 2][i] = ' ';
		}
	}
	else
	{
		int divideNum = (c2 - c1) * (rand() % 3 + 4) / 10;

		//방 분할
		temp1 = divideDungeon(depth - 1, r1, c1, r2, c1 + divideNum);
		temp2 = divideDungeon(depth - 1, r1, c1 + divideNum, r2, c2);

		//방 합치기
		map[(temp1.r3 + temp1.r4) / 2][temp1.c4 + 1] = ' ';
		map[(temp1.r3 + temp1.r4) / 2][temp1.c4 + 2] = ' ';
		map[(temp2.r1 + temp2.r2) / 2][temp2.c1 - 1] = ' ';
		map[(temp2.r1 + temp2.r2) / 2][temp2.c1 - 2] = ' ';

		int rmin = min((temp1.r3 + temp1.r4) / 2, (temp2.r1 + temp2.r2) / 2);
		int rmax = max((temp1.r3 + temp1.r4) / 2, (temp2.r1 + temp2.r2) / 2);
			
		for (int i = rmin;i <= rmax;i++)
		{
			map[i][temp2.c1 - 2] = ' ';
		}
	}

	location.r1 = temp1.r1, location.r2 = temp1.r2, location.c1 = temp1.c1, location.c2 = temp1.c2;
	location.r3 = temp2.r3, location.r4 = temp2.r4, location.c3 = temp2.c3, location.c4 = temp2.c4;

	return location;
}
