#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "Player.h"
#include "Monster.h"
#include "setting.h"
#include "Map.h"
#include "GameLoop.h"
#include "MakeTree.h"
#include "Timer.h"
#include "Hydra.h"
#include "Zombie.h"
#include "Troll.h"
#include "Dragon.h"

int arr[SIZE_ARR_X][SIZE_ARR_Y];
int roomnum = 2;
GameLoop G;



void PrintMap();

int main()
{
	srand((unsigned int)time(NULL));
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	
	TreeNode* treeNode = new TreeNode;
	treeNode->SetInfo(Matrix(0, 0, SIZE_ARR_X, SIZE_ARR_Y));
	treeNode->SetParentNode(NULL);
	srand(time(NULL));
	memset(arr, 0, sizeof(arr));


	MakeTree(treeNode);
	while (1)
	{
		MakeConnect(treeNode);
		if (treeNode->GetLeftNode()->GetRoomInfo().width > 0)
			break;
	}


	
	
	Player P;
	Troll troll;
	Zombie zombie;
	Hydra hydra;
	//Dragon hydra;
	Map M;
	Timer T;

	clock_t starttime = 0, endtime = 0;
	clock_t time = 0;

	G.AddObject(&T);
	
	G.AddObject(&M);
	G.AddObject(&troll);
	G.AddObject(&zombie);
	G.AddObject(&hydra);
	G.AddObject(&P);

	//Bomb* B = new Bomb;

	//G.AddObject(B);

	system("mode con:cols=200 lines=80");
	PrintMap();
	
	while (1)
	{
		G.Draw();
		G.Update();
		//static int cnt = 0;
		//cnt++;
		//if (cnt == 10000 )
		//{
		//	cnt = 0;
		//	Bomb* B2 = new Bomb;
		//
		//	G.AddObject(B2);
		//}
		
	}

}







void PrintMap()
{
	for (int i = 0; i < SIZE_ARR_Y; i++)
	{
		for (int j = 0; j < SIZE_ARR_X; j++)
		{
			gotoxy(j * 2, i);
			switch (arr[i][j])
			{
			case -1:
				cout << "¡Þ";
				break;
			case 0:
				cout << '+';			
				break;
			case 1:
				cout << 'X';
				break;
			default:
				//printf("%d", arr[i][j]);
				cout << ' ';
				break;
			}
		}
	}
}