#include "GameLoop.h"
#include "setting.h"

GameLoop::GameLoop()
{
	// �����ڿ��� �߰� �ʱ�ȭ�� �ʿ� ����
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

		if (obj->objectType == PLAYER) // �÷��̾
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
	if (arr[obj->getY()][obj->getX()] == 0 || arr[obj->getY()][obj->getX()] == 2) // �ʰ� �浹
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

	for (auto& otherObj : Objects) // ���Ϳ� �浹
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
				playerObj->RollbackUpdate(); // �ϴ��� �ѹ� ���� HP ���ҷ� ����
			}
		}
	}
}

void GameLoop::MonsterCollision(Object* obj, vector<Object*> object)
{
	for (auto& otherObj : object)
	{
		if (&obj == &otherObj)
		{
			continue;
		}

		if (otherObj == nullptr)
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