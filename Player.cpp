#include "Player.h"
#include "setting.h"
#include "GameLoop.h"

extern GameLoop G;


Player::Player()
{
	x = 5; y = 5;
	dir = 0;
	count = 0;
	objectType = PLAYER;
	Cname = "Knight";
	pclass = new Knight();
	hp = 30;
	if (pclass == nullptr) {
		cout << "¿À·ù";
	}
}

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
	this->pclass->attack(x, y, dir);
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

	this->pclass->Draw_BT();

	gotoxy(0, 61);
	cout << "HP: " << hp;
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

	this->pclass->Update_BT();
}

void Player::KeyEvent(int input)
{
	gotoxy(0, 22);
	static int a = 0;

	if (this->pclass->isSkill)
	{
		switch (input)
		{
		case LEFT:
			dir = static_cast<int>(Pdir::LEFT);
			break;
		case RIGHT:
			dir = static_cast<int>(Pdir::RIGHT);
			break;
		case UP:
			dir = static_cast<int>(Pdir::UP);
			break;
		case DOWN:
			dir = static_cast<int>(Pdir::DOWN);
			break;
		case ESC:
			_getch();
			//exit(0);
			break;
		case SPACE:
			//atkx = x;atky = y;
			//count = 1;
			this->attack();
			break;
		case ENTER:
			this->action();
			break;
		case TAP:
			this->pclass->Skill(x, y, dir);
			break;
		default:
			break;
		}
	}
	else
	{
		switch (input)
		{
		case LEFT:
			if (x <= 1)
				break;
			gotoxy(x * 2, y);
			cout << " ";
			x--;
			dir = static_cast<int>(Pdir::LEFT);
			break;
		case RIGHT:
			if (x >= Map_x - 1)
				break;
			gotoxy(x * 2, y);
			cout << " ";
			x++;
			dir = static_cast<int>(Pdir::RIGHT);
			break;
		case UP:
			if (y <= 1)
				break;
			gotoxy(x * 2, y);
			cout << " ";
			y--;
			dir = static_cast<int>(Pdir::UP);
			break;
		case DOWN:
			if (y >= Map_y - 1)
				break;
			gotoxy(x * 2, y);
			cout << " ";
			y++;
			dir = static_cast<int>(Pdir::DOWN);
			break;
		case ESC:
			_getch();
			//exit(0);
			break;
		case SPACE:
			//atkx = x;atky = y;
			//count = 1;
			this->attack();
			break;
		case ENTER:
			this->action();
			break;
		case TAP:
			this->pclass->Skill(x, y, dir);
			break;
		case Q:
		{
			Bomb* B = new Bomb(x, y);
			G.AddObject(B);
		}
			break;
		default:
			break;
		}
	}
	
	
	
}

void Player::RollbackUpdate()
{
	x = rx;
	y = ry;
}

void Player::MoveToPosition()
{
	rx = x, ry = y;
}

void Player::setDir(int _dir)
{
	dir = _dir;
}

int Player::getDir()
{
	return dir;
}