#include "GameLoop.h"
#include "setting.h"
//
//GameLoop::GameLoop()
//{
//	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
//	{
//		O[i] = nullptr;
//	}
//	
//}
//
//void GameLoop::AddObject(Player *_P)
//{
//	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
//	{
//		if (O[i] == nullptr)
//		{
//			O[i] = _P;
//			break;
//		}
//	}
//}
//	
//void GameLoop::AddObject(Map *_M)
//{
//	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
//	{
//		if (O[i] == nullptr)
//		{
//			O[i] = _M;
//			break;
//		}
//	}
//}
//
//void GameLoop::AddObject(Monster* _M)
//{
//	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
//	{
//		if (O[i] == nullptr)
//		{
//			O[i] = _M;
//			break;
//		}
//	}
//}
//
//void GameLoop::AddObject(Timer* _T)
//{
//	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
//	{
//		if (O[i] == nullptr)
//		{
//			O[i] = _T;
//			break;
//		}
//	}
//}
//
//void GameLoop::AddObject(Bomb* _I)
//{
//	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
//	{
//		if (O[i] == nullptr)
//		{
//			O[i] = _I;
//			break;
//		}
//	}
//}
//
//void GameLoop::DeleteObject(Bomb* _I)
//{
//	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
//	{
//		if (O[i] == _I)
//		{
//			O[i] = nullptr;
//			break;
//		}
//	}
//}
//
//void GameLoop::Draw()
//{
//	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
//	{
//		if (O[i] != nullptr)
//			O[i]->Draw();
//		else
//			break;
//	}
//		
//}
//
//void GameLoop::Update()
//{
//	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
//	{
//		if (O[i] != nullptr)
//		{
//			O[i]->Update();
//			if (O[i]->objectType == PLAYER) // 플레이어가
//			{
//				for (int j = 0; j < sizeof(O) / sizeof(O[0]); j++) // 몬스터와 충돌
//				{
//					if (i == j)
//					{
//						continue;
//					}
//					if (O[j] != nullptr && O[j]->objectType == MONSTER)
//					{
//						if (O[i]->getX() == O[j]->getX() && O[i]->getY() == O[j]->getY()) 
//						{
//							static_cast<Player*>(O[i])->RollbackUpdate(); // 일단은 롤백 추후 HP 감소로 변경
//						}
//					}
//				}
//
//				if (arr[O[i]->getY()][O[i]->getX()] == 0) // 맵과 충돌
//				{
//					static_cast<Player*>(O[i])->RollbackUpdate();
//				}
//				else
//				{
//					static_cast<Player*>(O[i])->MoveToPosition();
//				}
//			}
//			else if (O[i]->objectType == MONSTER)
//			{
//				for (int j = 0; j < sizeof(O) / sizeof(O[0]); j++)
//				{
//					if (i == j)
//					{
//						continue;
//					}
//					if (O[j] != nullptr && O[j]->objectType == PLAYER)
//					{
//						Cclass* temp;
//						temp = static_cast<Player*>(O[j])->getPclass();
//						for (auto it = temp->weapon->bt.begin(); it != temp->weapon->bt.end();)
//						{
//							if ((O[i]->getX() == it->getX()) && (O[i]->getY() == it->getY()))
//							{
//								static_cast<Monster*>(O[i])->calculateDamage(temp->weapon->getDamage());
//								if ((O[i])->getHP() <= 0)
//								{
//									O[i]->setDel(true);
//								}
//							}
//							++it;
//						}
//					}
//				}
//			}
//		}
//		else
//			break;
//	}
//
//	for (int i = 0;i < sizeof(O) / sizeof(O[0]);i++)
//	{
//		if (O[i] != nullptr)
//			if (O[i]->getDel())
//			{
//				delete O[i];
//				O[i] = nullptr;
//			}
//				
//	}
//}


GameLoop::GameLoop()
{
    // 생성자에서 추가 초기화는 필요 없음
}

void GameLoop::AddObject(Player* _P)
{
    O.push_back(_P);
}

void GameLoop::AddObject(Map* _M)
{
    O.push_back(_M);
}

void GameLoop::AddObject(Monster* _M)
{
    O.push_back(_M);
}

void GameLoop::AddObject(Timer* _T)
{
    O.push_back(_T);
}

void GameLoop::AddObject(Bomb* _I)
{
    O.push_back(_I);
}

void GameLoop::DeleteObject(Bomb* _I)
{
    for (auto it = O.begin(); it != O.end(); ++it)
    {
        if (*it == _I)
        {
            O.erase(it);
            break;
        }
    }
}

void GameLoop::Draw()
{
    for (const auto& obj : O)
    {
        if (obj != nullptr)
            obj->Draw();
        else
            break;
    }
}

void GameLoop::Update()
{
    for (auto& obj : O)
    {
        if (obj != nullptr)
        {
            obj->Update();

            if (obj->objectType == PLAYER) // 플레이어가
            {
                Player* playerObj = dynamic_cast<Player*>(obj);

                for (auto& otherObj : O) // 몬스터와 충돌
                {
                    if (&obj == &otherObj)
                    {
                        continue;
                    }

                    if (otherObj != nullptr && otherObj->objectType == MONSTER)
                    {
                        if (obj->getX() == otherObj->getX() && obj->getY() == otherObj->getY())
                        {
                            if (playerObj != nullptr)
                            {
                                playerObj->RollbackUpdate();
                            }// 일단은 롤백 추후 HP 감소로 변경
                        }
                    }
                }

                if (arr[obj->getY()][obj->getX()] == 0) // 맵과 충돌
                {
                    if (playerObj != nullptr)
                    {
                        playerObj->RollbackUpdate();
                    }
                }
                else
                {
                    if (playerObj != nullptr)
                    {
                        playerObj->MoveToPosition();
                    }
                }
            }
            else if (obj->objectType == MONSTER)
            {
                for (auto& otherObj : O)
                {
                    if (&obj == &otherObj)
                    {
                        continue;
                    }
                    if (otherObj != nullptr && otherObj->objectType == PLAYER)
                    {
                        Player* playerObj = dynamic_cast<Player*>(otherObj);
                        if (playerObj != nullptr)
                        {
                            Cclass* temp = playerObj->getPclass();
                            for (auto it = temp->weapon->bt.begin(); it != temp->weapon->bt.end();)
                            {
                                if ((obj->getX() == it->getX()) && (obj->getY() == it->getY()))
                                {
                                    Monster* monsterObj = dynamic_cast<Monster*>(obj);
                                    if (monsterObj != nullptr)
                                    {
                                        monsterObj->calculateDamage(temp->weapon->getDamage());
                                        if (monsterObj->getHP() <= 0)
                                        {
                                            monsterObj->setDel(true);
                                        }
                                    }
                                }
                                ++it;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            break;
        }
    }

    O.erase(std::remove_if(O.begin(), O.end(), [](Object* obj) { return obj != nullptr && obj->getDel(); }), O.end());
}