#include "GameLoop.h"
#include "setting.h"

void PrintMap();

void MakeTree(TreeNode* treeNode, GameLoop* G);
void MakeConnect(TreeNode* treeNode);
void MakeBossRoom();
void preorder(TreeNode* tree, Matrix* ptr, int rm);


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
			HandlePlayerPortalCollision(playerObj, obj);
		}
		else if (obj->objectType == MONSTER)
		{
			MonsterCollision(obj, Objects);
		}

	}

	Objects.erase(std::remove_if(Objects.begin(), Objects.end(), [](Object* obj) { return obj != nullptr && obj->getDel(); }), Objects.end());
}

void GameLoop::HandlePlayerMapCollision(Player* playerObj, Object* obj) {
	if (arr[obj->getY()][obj->getX()] == 0 || arr[obj->getY()][obj->getX()] == 1) // 맵과 충돌
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

void GameLoop::HandlePlayerPortalCollision(Player* playerObj, Object* obj)
{
	for (auto& otherObj : Objects) 
	{
		if (otherObj->objectType == PORTAL && roomcnt < 3)
		{	
			if (obj->getX() == otherObj->getX() && obj->getY() == otherObj->getY())
			{
				otherObj->setDel(true);
				roomnum = 2;

				TreeNode* treeNode = new TreeNode;
				treeNode->SetInfo(Matrix(0, 0, SIZE_ARR_X, SIZE_ARR_Y));
				treeNode->SetParentNode(NULL);
			
				memset(arr, 0, sizeof(arr));


				MakeTree(treeNode, this);
				while (1)
				{
					MakeConnect(treeNode);
					if (treeNode->GetLeftNode()->GetRoomInfo().width > 0)
						break;
				}
				
				Matrix ptr;
				preorder(treeNode, &ptr, roomnum);
				int x = (ptr.width + ptr.x) / 2;
				int y = (ptr.height + ptr.y) / 2;
				playerObj->setX(x);
				playerObj->setX(y);
				

				system("cls");
				PrintMap();

				roomcnt++;
			}
		}
		if (otherObj->objectType == PORTAL && roomcnt == 3)
		{
			otherObj->setDel(true);
			MakeBossRoom();
			system("cls");
			PrintMap();
			playerObj->setX(29);
			playerObj->setY(55);
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


void preorder(TreeNode* tree, Matrix* ptr, int rm)
{
	if (tree == nullptr)
		return;
	
	if (tree->GetRoomN() == rm - 1)
	{
		*ptr = tree->GetRoomInfo();
		return;
	}		
	preorder(tree->GetLeftNode(), ptr, rm);
	preorder(tree->GetRightNode(), ptr, rm);
	
}