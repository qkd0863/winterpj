#pragma once
#include "setting.h"

class Object
{
private:
	int x, y;
	BOOL del = false;
public:
	virtual void Draw();
	virtual void Update();
	virtual int getX();
	virtual int getY();
	void setDel(BOOL _d) { del = _d; };
	BOOL getDel() { return del; };

};

