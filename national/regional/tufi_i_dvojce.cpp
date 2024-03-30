#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int TM1, TS1, TM2, TS2, DM1, DS1, DM2, DS2;
    cin >> TM1 >> TS1 >> TM2 >> TS2 >> DM1 >> DS1 >> DM2 >> DS2;
    TS1 += TM1 * 60;
    TS2 += TM2 * 60;
    DS1 += DM1 * 60;
    DS2 += DM2 * 60;
    int a, b;
    a = TS1 + TS2;
    b = DS1 + DS2;
    if (a > b)
        cout << "D" << endl;
    else
        cout << "T" << endl;
    int rez = abs(a - b);
    int g = 0;
    while (rez >= 60)
    {
        rez -= 60;
        g++;
    }
    cout << g << " " << rez;
    return 0;
}