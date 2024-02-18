#pragma once
#include "Player.h"
#include "Monster.h"
#include "Map.h"
#include "Object.h"
#include "Timer.h"
#include "Bomb.h"


class GameLoop
{
private:
	vector<Object*> Objects;
public:
	GameLoop();
	void AddObject(Object* _P);
	void DeleteObject(Object* _P);
	void Draw();
	void Update();
	void HandlePlayerMapCollision(Player* playerObj, Object* obj);
	void HandlePlayerMonsterCollision(Object* obj, vector<Object*> object);
	void HandlePlayerPortalCollision(Player* playerObj, Object* obj);
	void MonsterCollision(Object* obj, vector<Object*> object);
};

