#pragma once
#include "Object.h"
#include "Timer.h"
#include "Weapon.h"
#include "Pistol.h"
#include "Cclass.h"
#include "Gunner.h"
#include "Knight.h"
#include "Magician.h"
#include <vector>

using namespace std;

enum class Pdir
{
	RIGHT = 0,
	LEFT = 180,
	UP = 90,
	DOWN = 270
};

class Player :public Object
{	
private:
	int rx; int ry;
	//int atkx = 0, atky = 0;
	int dir;
	double count;
	BOOL Barrier = false;
	Timer Cnt;
	string Cname;
	Cclass* pclass;
public:
	BOOL AddBomb = false;
public:
	Player();
	int getX();
	int getY();
	int getDir(); // 방향 리턴
	BOOL getBarrier() { return Barrier; }
	void setX(int _x);
	void setY(int _y);
	void setDir(int _dir); // 방향 설정
	void action();
	void attack();
	void DrawSpace(int x, int y);
	void setBarrier(BOOL _b) { Barrier = _b; }
	virtual void Draw();
	virtual void Update();
	void KeyEvent(int input);
	void RollbackUpdate();
	void MoveToPosition();
	void SelectClass(int num);
	void calculateDamage(int _damage) { hp -= _damage; }
	Cclass* getPclass() const {
		return pclass;
	}
};
