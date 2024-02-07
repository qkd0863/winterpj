#include "GameLoop.h"
#include "setting.h"

GameLoop::GameLoop()
{
    // �����ڿ��� �߰� �ʱ�ȭ�� �ʿ� ����
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

            if (obj->objectType == PLAYER) // �÷��̾
            {
                Player* playerObj = dynamic_cast<Player*>(obj);

                for (auto& otherObj : O) // ���Ϳ� �浹
                {
                    if (&obj == &otherObj)
                    {
                        continue;
                    }

                    if (otherObj != nullptr && otherObj->objectType == MONSTER)
                    {
                        Monster* monsterobj = dynamic_cast<Monster*>(otherObj);
                        if (obj->getX() == monsterobj->getX() && obj->getY() == monsterobj->getY())
                        {
                            if (playerObj != nullptr)
                            {
                                playerObj->calculateDamage(monsterobj->getDamage());
                                playerObj->RollbackUpdate();
                            }// �ϴ��� �ѹ� ���� HP ���ҷ� ����
                        }
                    }
                }

                if (arr[obj->getY()][obj->getX()] == 0) // �ʰ� �浹
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