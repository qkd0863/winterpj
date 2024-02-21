#pragma once
#include "setting.h"

enum CobjectType {
	PLAYER = 0,
	MONSTER,
	MAP,
	BOMB,
	TIMER,
	BULLET,
	MAPMGR,
	PORTAL,
	DELETEHURDLE,
	BARRIER
};

class Object
{
protected:
	int x, y;
	int hp;
private:
	BOOL del = false;
public:
	CobjectType objectType;
	virtual void Draw();
	virtual void Update();
	virtual int getX();
	virtual int getY();
	virtual int getHP();
	virtual void calculateDamage(int damage);
	void setDel(BOOL _d) { del = _d; };
	BOOL getDel() { return del; };
	

};

