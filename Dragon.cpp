#include "Dragon.h"

Dragon::Dragon()
{
    hp = 200;
    x = 20;
    y = 5;
    IsAttack = false;
    IsBreath = false;
    BreathY = 17;
    TBreath = 0;
    objectType = BOSS;
}

void Dragon::Draw()
{
    if (!del) 
    {
        gotoxy(x * 2, y);                                                             //            11           111           
        cout << "          11           111          " << endl;                       //           1111         1111           
        gotoxy(x * 2, y + 1);                                                         //           11111       11111           
        cout << "          1111         1111         " << endl;                       //            11111     111111           
        gotoxy(x * 2, y + 2);                                                         //           11   111 111   11           
        cout << "         11111       11111          " << endl;                       //            1             11           
        gotoxy(x * 2, y + 3);                                                         //           11             11           
        cout << "          11111     111111          " << endl;                       //          11               11          
        gotoxy(x * 2, y + 4);                                                         //  111    11                 11     11  
        cout << "          11   111 111   11         " << endl;                       //  111111111    11      1    111111111  
        gotoxy(x * 2, y + 5);                                                         //  11111111111              11111111111 
        cout << "          1             11          " << endl;                       //  111111111111           111 111111111 
        gotoxy(x * 2, y + 6);                                                         //  111 111111 1111     1111 111111 1111 
        cout << "         11             11          " << endl;                       //  1      1111 11111111111 1111      1  
        gotoxy(x * 2, y + 7);                                                         //         11111  1111111   1111         
        cout << "        11               11         " << endl;                       //          11111  11111  11111          
        gotoxy(x * 2, y + 8);                                                         //              11111 11111              
        cout << "111    11                 11     11 " << endl;
        gotoxy(x * 2, y + 9);
        cout << "111111111    11      1    111111111 " << endl;
        gotoxy(x * 2, y + 10);
        cout << "11111111111              11111111111" << endl;
        gotoxy(x * 2, y + 11);
        cout << "111111111111           111 111111111" << endl;
        gotoxy(x * 2, y + 12);
        cout << "111 111111 1111     1111 111111 1111" << endl;
        gotoxy(x * 2, y + 13);
        cout << "1      1111 11111111111 1111      1 " << endl;
        gotoxy(x * 2, y + 14);
        cout << "       11111  1111111   1111        " << endl;
        gotoxy(x * 2, y + 15);
        cout << "         11111  11111  11111        " << endl;
        gotoxy(x * 2, y + 16);
        cout << "             11111 11111            " << endl;
    }
    else
    {
        for (int i = 0; i < 61; i++)
        {
            gotoxy(x * 2, y + i);
            cout << "                                    " << endl;
        }
    }
}

void Dragon::Update()
{
    Cnt.Update();
    if (IsAttack)
    {
        TBreath += Cnt.getDelta();
    }
    else
    {
        turn += Cnt.getDelta();
    }

    if (turn >= 1)
    {
        //DrawSpace();  움직일때

        IsAttack = true;
        turn = 0;
    }

    if (IsAttack)
    {
        Attack();
    }

    
}

void Dragon::DrawSpace()
{
    for (int i = 0; i < 16; i++)
    {
        gotoxy(x * 2, y + i);
        cout << "                                    " << endl;
    }
}

void Dragon::Attack()
{
    if (IsBreath == false)
    {
        if (TBreath < 10.0)
        {
            if (BreathY < 54)
            {
                gotoxy(x * 2, y + BreathY);
                cout << "!                                   !" << endl;
                BreathY++;
            }
        }
        else
        {
            BreathY = 17;
            IsBreath = true;
            TBreath = 0;
        }
    }
    else
    {
        if (TBreath < 10.0)
        {
            gotoxy(x * 2, y + BreathY);
            cout << "|||||||||||||||||||||||||||||||||||||" << endl;

            if (BreathY < 54)
            {
                BreathY++;
            }
        }
        else
        {
            TBreath = 0;
            IsBreath = false;
            BreathY = 17;
            IsAttack = false;
        }
    }
}
