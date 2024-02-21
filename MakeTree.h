#include "TreeNode.h"
#include "Portal.h"
#include "DeleteHurdle.h"
#include "Barrier.h"
#include "Zombie.h"

void GenerateMonster(int n, Matrix M, GameLoop* G);

void MakeTree(TreeNode* treeNode,GameLoop* G)
{
	Matrix mat1, mat2;

	int direction;
	int num = rand() % 2;
	float num1 = rand() % 20 + 40;
	if (num == 0)
	{
		direction = WIDTH;
		int num2 = (treeNode->GetInfo().width - treeNode->GetInfo().x) * (num1 / 100);
		mat1.width = treeNode->GetInfo().width - num2;
		mat2.x = treeNode->GetInfo().width - num2;
		mat1.x = treeNode->GetInfo().x;
		mat2.width = treeNode->GetInfo().width;
		mat1.y = treeNode->GetInfo().y;
		mat2.y = treeNode->GetInfo().y;
		mat1.height = treeNode->GetInfo().height;
		mat2.height = treeNode->GetInfo().height;
	}
	else
	{
		direction = HEIGHT;
		int num2 = (treeNode->GetInfo().height - treeNode->GetInfo().y) * (num1 / 100);
		mat1.height = treeNode->GetInfo().height - num2;
		mat2.y = treeNode->GetInfo().height - num2;
		mat1.y = treeNode->GetInfo().y;
		mat2.height = treeNode->GetInfo().height;
		mat1.x = treeNode->GetInfo().x;
		mat2.x = treeNode->GetInfo().x;
		mat1.width = treeNode->GetInfo().width;
		mat2.width = treeNode->GetInfo().width;
	}
	//std::cout << treeNode->GetInfo().x << ' '
	//	<< treeNode->GetInfo().y << ' '
	//	<< treeNode->GetInfo().width << ' '
	//	<< treeNode->GetInfo().height << std::endl;
	if (mat1.width - mat1.x < 10 ||
		mat1.height - mat1.y < 10 ||
		mat2.width - mat2.x < 10 ||
		mat2.height - mat2.y < 10)
	{
		int a = rand() % 4 + 1;
		int b = rand() % 4 + 1;
		int c = rand() % 4 + 1;
		int d = rand() % 4 + 1;
		for (int i = treeNode->GetInfo().y + c; i < treeNode->GetInfo().height - d; i++)
		{
			for (int j = treeNode->GetInfo().x + a; j < treeNode->GetInfo().width - b; j++)
			{
				arr[i][j] = roomnum;
			}
		}
		treeNode->SetRoomN(roomnum);
		roomnum++;
		treeNode->SetSolo(true);
		treeNode->SetRoomInfo(Matrix(treeNode->GetInfo().x + a,
			treeNode->GetInfo().y + c,
			treeNode->GetInfo().width - b,
			treeNode->GetInfo().height - d));
		if (roomnum != 3)	//ù��° roomnum==3
			treeNode->MakeHurdle(treeNode->GetRoomInfo());
		
		
		/*if (roomnum == 3)
		{
			Matrix M = treeNode->GetRoomInfo();
			Portal* P = new Portal((M.width + M.x) / 2, (M.height + M.y) / 2);
			G->AddObject(P);
		}
	*/
		


		return;
	}
	treeNode->MakeLeftTree(new TreeNode);
	treeNode->GetLeftNode()->SetInfo(mat1);
	treeNode->GetLeftNode()->SetParentNode(treeNode);
	treeNode->GetLeftNode()->SetDirection(direction);
	MakeTree(treeNode->GetLeftNode(),G);
	treeNode->MakeRightTree(new TreeNode);
	treeNode->GetRightNode()->SetInfo(mat2);
	treeNode->GetRightNode()->SetParentNode(treeNode);
	treeNode->GetRightNode()->SetDirection(direction);
	MakeTree(treeNode->GetRightNode(),G);
	return;
}
void MakeConnect(TreeNode* treeNode)
{
	if (!treeNode->GetLeftNode())
	{
		if (treeNode->GetParentNode()->GetLeftNode() == treeNode)
			treeNode->MakeConnection();
		return;
	}
	else if (treeNode->GetRoomInfo().width > 0)
	{
		if (!treeNode->GetParentNode())
			return;
		if (treeNode->GetParentNode()->GetLeftNode() == treeNode)
			treeNode->MakeConnection();
		return;
	}
	else
	{
		MakeConnect(treeNode->GetLeftNode());
		MakeConnect(treeNode->GetRightNode());
	}
}
void MakeBossRoom()
{
	for (int i = 0;i < SIZE_ARR_X;i++)
	{
		for (int j = 0;j < SIZE_ARR_Y;j++)
		{
			if (j == 0 || i == 0 || j == SIZE_ARR_Y-1 || i == SIZE_ARR_X-1)
				arr[j][i] = 0;
			else
				arr[j][i] = 2;
		}
	}
}

void GenerateMonster(int n, Matrix M, GameLoop *G)
{
	switch (n)
	{
	case 0:
	{
		Zombie* Z = new Zombie((M.width + M.x) / 2, (M.height + M.y) / 2);
		G->AddObject(Z);
	}
		break;
	case 1:
		//Troll * T = new Troll((M.width + M.x) / 2, (M.height + M.y) / 2);
		//G.AddObject(T);
		break;
	case 2:
		//Hydra * J = new Hydra((M.width + M.x) / 2, (M.height + M.y) / 2);
		//G.AddObject(H);
		break;
	default:
		break;
	}

}