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
public:
	Weapon();
	virtual double get_speed() = 0;
	virtual void Shot() = 0;
};


class Pistol : public Weapon
{
private:
	  int damage;
	  double speed;
public:
	  vector <Bullet> bt;
	  Pistol();
	  double get_speed() override;
	  void Shot() override;
};

class Shotgun : public Weapon
{
private:
	int damage;
	double speed;
public:
	vector <Bullet> bt;
	Shotgun();
	double get_speed() override;
	void Shot() override;
};

