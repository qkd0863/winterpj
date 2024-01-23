#pragma once
class Object
{
private:
	int x, y;
public:
	virtual void Draw();
	virtual void Update();
	virtual int getX();
	virtual int getY();
};

