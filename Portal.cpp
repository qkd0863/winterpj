#include "Portal.h"

Portal::Portal(int _x, int _y)
{
	x = _x;y = _y;
	objectType = PORTAL;
}

void Portal::Draw()
{
	gotoxy(x * 2, y);
	cout << "¡Þ";
}

void Portal::Update()
{
}
