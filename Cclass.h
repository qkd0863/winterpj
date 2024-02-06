#pragma once
#include "Weapon.h"
#include "Shotgun.h"
class Cclass
{
private:
public:
    Cclass();
    ~Cclass();
    Weapon* weapon;
    string wname;
    bool isSkill;
    virtual void setWeapon() {
    };
    virtual void attack(int _x, int _y, int _dir) {
        weapon->Shot(_x, _y, _dir);
    }
    virtual void Draw_BT() {};
    virtual void Update_BT()
    {
        weapon->UpdateBullets();
    }
    virtual void Skill(int _x, int _y, int _dir) = 0;
};

