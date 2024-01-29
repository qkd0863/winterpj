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
    virtual void setWeapon() {
    };
    virtual void attack(int _x, int _y, int _dir) {
        weapon->Shot(_x, _y, _dir);
        cout << "공격합니다!";
    }
    virtual void Draw_BT()
    {
        if (weapon != nullptr) {
            weapon->DrawBullets();
        }
        else
        {
            weapon = new Shotgun();
        }
    }
    virtual void Update_BT()
    {
        weapon->UpdateBullets();
    }
};

