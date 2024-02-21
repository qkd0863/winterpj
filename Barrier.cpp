#include "Barrier.h"

Barrier::Barrier(int _x, int _y)
{
	x = _x, y = _y;
	objectType = BARRIER;
}

void Barrier::Draw()
{
	gotoxy(x * 2, y);
	cout << "¡Ú";
}

void Barrier::Update()
{
}

void Barrier::Activate()
{
}
