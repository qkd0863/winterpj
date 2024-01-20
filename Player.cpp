#include "Player.h"
#include "setting.h"



int Player::getX()
{
	return x;
}
int Player::getY()
{
	return y;
}
void Player::setX(int _x)
{
	x = _x;
}
void Player::setY(int _y)
{
	y = _y;
}

void Player::action()
{
	cout << "action" << endl;
}

void Player::attack()
{
	gotoxy((x + 1) * 2, y);
	cout << "X";
	gotoxy((x - 1) * 2, y);
	cout << "X";
	gotoxy(x * 2, (y + 1));
	cout << "X";
	gotoxy(x * 2, (y - 1));
	cout << "X";
}

void Player::DrawSpace(int a, int b)
{
	if (a > 0 && b > 0)
	{
		gotoxy((a + 1) * 2, b);
		cout << " ";
		gotoxy((a - 1) * 2, b);
		cout << " ";
		gotoxy(a * 2, (b + 1));
		cout << " ";
		gotoxy(a * 2, (b - 1));
		cout << " ";
	}
}

void Player::Draw()
{
	gotoxy(x * 2, y);
	cout << "P";
}

void Player::Update()
{
	Cnt.Update();

	if (count > 0)
		count -= Cnt.getDelta();


	int input = _kbhit();
	if (input)
	{
		int c = 0;
		c = _getch();
		this->KeyEvent(c);
	}

	if (count <= 0)
		this->DrawSpace(atkx, atky);
}

void Player::KeyEvent(int input)
{
	gotoxy(0, 22);
	static int a = 0;


	
	switch (input)
	{
	case LEFT:
		if (x <= 1)
			break;
		gotoxy(x * 2, y);
		cout << " ";
		x--;
		break;
	case RIGHT:
		if (x >= Map_x - 1)
			break;
		gotoxy(x * 2, y);
		cout << " ";
		x++;
		break;
	case UP:
		if (y <= 1)
			break;
		gotoxy(x * 2, y);
		cout << " ";
		y--;
		break;
	case DOWN:
		if (y >= Map_y - 1)
			break;
		gotoxy(x * 2, y);
		cout << " ";
		y++;
		break;
	case ESC:
		_getch();
		//exit(0);
		break;
	case SPACE:
		atkx = x;atky = y;
		count = 1;
		this->attack();
		break;
	case ENTER:
		this->action();
		break;
	default:
		break;
	}
	

}
