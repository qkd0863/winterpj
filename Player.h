#pragma once
#include "Object.h"
#include "Timer.h"
#include "Weapon.h"
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
	int x = 5;int y = 5;
	int atkx = 0, atky = 0;
	int dir = 0;
	double count = 0;
	Timer Cnt;
	vector<Bullet> bt;
	Pistol wp;
	int wp_slot = Wp_slot::FIR;
public:
	int getX();
	int getY();
	int getDir(); // 방향 리턴
	void setX(int _x);
	void setY(int _y);
	void setDir(int _dir); // 방향 설정
	void action();
	void attack();
	void DrawSpace(int x, int y);
	virtual void Draw();
	virtual void Update();
	void KeyEvent(int input);
	void Change_BT_Dir(int _dir, Bullet* bullet); // 플레이어 방향에 따른 총알 방향 설정
};
