#include "GameLoop.h"
#include "setting.h"

GameLoop::GameLoop()
{
	// 생성자에서 추가 초기화는 필요 없음
}

void GameLoop::AddObject(Object* _P)
{
	Objects.push_back(_P);
}

void GameLoop::DeleteObject(Object* _P)
{
	for (auto it = Objects.begin(); it != Objects.end(); ++it)
	{
		if (*it == _P)
		{
			Objects.erase(it);
			break;
		}
	}
}

void GameLoop::Draw()
{
	for (const auto& obj : Objects)
	{
		if (obj != nullptr)
			obj->Draw();
		else
			break;
	}
}

void GameLoop::Update()
{
	for (auto& obj : Objects)
	{
		if (obj == nullptr) { break; }

		obj->Update();

		if (obj->objectType == PLAYER) // 플레이어가
		{
			Player* playerObj = dynamic_cast<Player*>(obj);
			HandlePlayerMonsterCollision(obj, Objects);
			HandlePlayerMapCollision(playerObj, obj);
		}
		else if (obj->objectType == MONSTER)
		{
			MonsterCollision(obj, Objects);
		}

	}

	Objects.erase(std::remove_if(Objects.begin(), Objects.end(), [](Object* obj) { return obj != nullptr && obj->getDel(); }), Objects.end());
}

void GameLoop::HandlePlayerMapCollision(Player* playerObj, Object* obj) {
	if (arr[obj->getY()][obj->getX()] == 0 || arr[obj->getY()][obj->getX()] == 2) // 맵과 충돌
	{
		playerObj->RollbackUpdate();
	}
	else
	{
		playerObj->MoveToPosition();
	}
}

void GameLoop::HandlePlayerMonsterCollision(Object* obj, vector<Object*> object) {
	Player* playerObj = dynamic_cast<Player*>(obj);

	for (auto& otherObj : Objects) // 몬스터와 충돌
	{
		if (otherObj == nullptr)
		{
			continue;
		}

		if (&obj == &otherObj)
		{
			continue;
		}


		if (otherObj->objectType == MONSTER)
		{
			Monster* monsterobj = dynamic_cast<Monster*>(otherObj);
			if (obj->getX() == monsterobj->getX() && obj->getY() == monsterobj->getY())
			{
				playerObj->calculateDamage(monsterobj->getDamage());
				playerObj->RollbackUpdate(); // 일단은 롤백 추후 HP 감소로 변경
			}
		}
	}
}

void GameLoop::MonsterCollision(Object* obj, vector<Object*> object)
{
	for (auto& otherObj : object)
	{
		if (otherObj == nullptr)
		{
			continue;
		}

		if (&obj == &otherObj)
		{
			continue;
		}


		if (otherObj->objectType == PLAYER)
		{
			Player* playerObj = dynamic_cast<Player*>(otherObj);
			if (playerObj == nullptr) { continue; }
			Cclass* temp = playerObj->getPclass();
			for (auto it = temp->weapon->bt.begin(); it != temp->weapon->bt.end();)
			{
				if ((obj->getX() == it->getX()) && (obj->getY() == it->getY()))
				{
					Monster* monsterObj = dynamic_cast<Monster*>(obj);
					monsterObj->calculateDamage(temp->weapon->getDamage());
					if (monsterObj->getHP() <= 0)
					{
						monsterObj->setDel(true);
					}
				}
				++it;
			}
		}
	}
}