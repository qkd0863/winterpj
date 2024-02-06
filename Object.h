#pragma once
#include "setting.h"

enum CobjectType {
	PLAYER = 0,
	MONSTER,
	MAP,
	BOMB,
	TIMER
};

class Object
{
protected:
private:
	int x, y;
	BOOL del = false;
public:
	CobjectType objectType;
	virtual void Draw();
	virtual void Update();
	virtual int getX();
	virtual int getY();
	void setDel(BOOL _d) { del = _d; };
	BOOL getDel() { return del; };

};

