#include "setting.h"

void TreeNode::MakeConnection()
{
	if (roominfo.x < NULL)
		return;
	float num = 50;
	if (direction == WIDTH)
	{
		int initY = roominfo.y * (num / 100) + roominfo.height * (num / 100);
		int initX = roominfo.width;

		int i = initX;
		while (1)
		{
			if (arr[initY][i] == 1 || i > 58)
				break;
			arr[initY][i] = 1;
			i++;
		}
	}
	if (direction == HEIGHT)	
	{
		int initX = roominfo.x * (num / 100) + roominfo.width * (num / 100);
		int initY = roominfo.height;
		/*for (int i = initY + 1; arr[i][initX] != 1; i++)
		{
			arr[i][initX] = 2;
		}*/
		int i = initY;
		while (1)
		{
			if (arr[i][initX] == 1 || i > 58)
				break;
			arr[i][initX] = 1;
			i++;
		}
	}
	connect = true;
	if (!parentNode->GetParentNode())
		return;
	parentNode->SetRoomInfo(parentNode->GetRightNode()->GetRoomInfo());
	if (parentNode != parentNode->parentNode->GetLeftNode())
		return;
	else
	{
		parentNode->MakeConnection();
	}
}

void TreeNode::MakeHurdle(Matrix romminfo)
{
	int cnt = 10;
	for (int i = romminfo.x;i < romminfo.width;i++)
	{
		for (int j = romminfo.y;j < romminfo.height;j++)
		{
			int n = rand() % 20;
			if (n % 20 == 0)
			{
				arr[j][i] = 2;
				cnt--;
			}
			if (cnt == 0)
				return;
		}
	}

}
