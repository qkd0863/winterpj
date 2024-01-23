#pragma once
#include "Object.h"
#include "Bullet.h"
#include <vector>

using namespace std;

namespace Wp_slot
{
	const int FIR = 0;
	const int SEC = 1;
}

class Weapon
{
private:
	const int MAX_BULLET = 100000000;
	int damage;
	double speed;
	int bullet_num = MAX_BULLET;
public:
	Weapon();
	double get_speed();
	void Reload();
public:
	vector <Bullet> bt;
};


//class Pistol : public Weapon
//{
//private:
//	  vector <Bullet> bt;
//	  const int MAX_BULLET = 100000000;
//	  int damage;
//	  int bullet_num = MAX_BULLET;
//public:
//	  Pistol();
//	  void Reload();
//};

