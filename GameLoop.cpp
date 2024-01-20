#include "GameLoop.h"
#include "setting.h"




GameLoop::GameLoop()
{
	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
	{
		O[i] = nullptr;
	}
	
}

void GameLoop::AddObject(Player *_P)
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
	
void GameLoop::AddObject(Map *_M)
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

void GameLoop::AddObject(Monster* _M)
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

void GameLoop::AddObject(Timer* _T)
{
	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
	{
		if (O[i] == nullptr)
		{
			O[i] = _T;
			break;
		}
	}
}

void GameLoop::Draw()
{
	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
	{
		if (O[i] != nullptr)
			O[i]->Draw();
		else
			break;
	}
		
}

void GameLoop::Update()
{
	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
	{
		if (O[i] != nullptr)
			O[i]->Update();
		else
			break;
	}
}
