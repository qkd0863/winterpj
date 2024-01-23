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
	/*gotoxy((x + 1) * 2, y);
	cout << "X";
	gotoxy((x - 1) * 2, y);
	cout << "X";
	gotoxy(x * 2, (y + 1));
	cout << "X";
	gotoxy(x * 2, (y - 1));
	cout << "X";*/

	for (auto i : wp.bt)
	{
		Change_BT_Dir(dir, &i);
	}
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

	for (auto& i : bt)
	{
		i.Draw();
	}
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

	//if (count <= 0)
	//	this->DrawSpace(atkx, atky);

	for (auto it = bt.begin(); it != bt.end();)
	{
		it->Update();
		if (it->getX() <= 0 || it->getX() >= Map_x || it->getY() <= 0 || it->getY() >= Map_y)
		{
			gotoxy(it->getX() * 2, it->getY());
			cout << " ";
			it = bt.erase(it);
		}
		else
		{
			++it;
		}
	}
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
	default:
		break;
	}
	
}

void Player::Change_BT_Dir(int _dir, Bullet* bullet)
{
	switch (_dir)
	{
	case static_cast<int>(Pdir::RIGHT):
		bt.emplace_back(getX() + 1, getY(), bullet->getDX(), bullet->getDY(), wp.get_speed());
		break;
	case static_cast<int>(Pdir::UP):
		bt.emplace_back(getX(), getY() - 1, bullet->getDY(), -(bullet->getDX()), wp.get_speed());
		break;
	case static_cast<int>(Pdir::LEFT):
		bt.emplace_back(getX() - 1, getY(), -(bullet->getDX()), -(bullet->getDY()), wp.get_speed());
		break;
	case static_cast<int>(Pdir::DOWN):
		bt.emplace_back(getX(), getY() + 1, -(bullet->getDY()), bullet->getDX(), wp.get_speed());
		break;
	}
}

void Player::setDir(int _dir)
{
	dir = _dir;
}

int Player::getDir()
{
	return dir;
}