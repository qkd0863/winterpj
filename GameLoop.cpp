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

void GameLoop::AddObject(Bomb* _I)
{
	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
	{
		if (O[i] == nullptr)
		{
			O[i] = _I;
			break;
		}
	}
}

void GameLoop::DeleteObject(Bomb* _I)
{
	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
	{
		if (O[i] == _I)
		{
			O[i] = nullptr;
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
		{
			O[i]->Update();
			if (O[i]->objectType == PLAYER) // 플레이어가
			{
				for (int j = 0; j < sizeof(O) / sizeof(O[0]); j++) // 몬스터와 충돌
				{
					if (i == j)
					{
						continue;
					}
					if (O[j] != nullptr && O[j]->objectType == MONSTER)
					{
						if (O[i]->getX() == O[j]->getX() && O[i]->getY() == O[j]->getY()) 
						{
							static_cast<Player*>(O[i])->RollbackUpdate(); // 일단은 롤백 추후 HP 감소로 변경
						}
					}
				}

				if (arr[O[i]->getY()][O[i]->getX()] == 0 || arr[O[i]->getY()][O[i]->getX()] == 2) // 맵과 충돌, 장애물과 충돌(임시로 못가게 만듦)
				{
					static_cast<Player*>(O[i])->RollbackUpdate();
				}
				else
				{
					static_cast<Player*>(O[i])->MoveToPosition();
				}
			}
		}
		else
			break;
	}

	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
	{
		if (O[i] != nullptr)
			if (O[i]->getDel())
			{
				delete[] O[i];
				O[i] = nullptr;
			}
				
	}
}
