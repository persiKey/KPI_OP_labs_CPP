/*/////////////////////////////////////////////////////////////////////

    ІП-13 Пархомчук Ілля (Вікторович)
    Варіант 26

***********************************************************************
    Трикутник заданий величинами своїх кутів і радіусом описаного кола.
    Знайти сторони трикуткика.

*//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <conio.h>
#include <math.h>

using std::cin;
using std::cout;

#define PI 3.14159265

int main()
{
    setlocale(LC_ALL, ".1251");
    system("chcp 1251 > null");

    float sides[3];

    float angles[3];
    float radius;

    cout << "Введіть кути: ";
    cin >> angles[0] >> angles[1] >> angles[2];

    cout << "Введіть радіус описаного кола: ";
    cin >> radius;

    /******************************

          a       b       c
        ----- = ----- = ----- = 2 R
        sin(a)  sin(b)  sin(c)

        a = 2 R * sin(a);

    ******************************/
    
    sides[0] = 2 * radius * sin(angles[0]/180*PI);
    sides[1] = 2 * radius * sin(angles[1]/180*PI);
    sides[2] = 2 * radius * sin(angles[2]/180*PI);
    

    printf("\nСторони:\n\ta = %.2f\n\tb = %.2f\n\tc = %.2f\n",
                            sides[0], sides[1], sides[2]);

    _getch();
    return 0;
}