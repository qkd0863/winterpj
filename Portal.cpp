#include "Portal.h"

Portal::Portal(int _x, int _y)
{
	x = _x;y = _y;
}

void Portal::Draw()
{
	gotoxy(x * 2, y);
	cout << "��";
}

void Portal::Update()
{
}
