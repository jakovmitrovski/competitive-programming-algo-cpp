#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int d = 0, den = 0, rez = 0;
    if (a == b)
    {
        cout << 1;
        return 0;
    }
    while (d < a)
    {
        if (den % 2 == 0)
        {
            d += b;
            rez++;
            den++;
            if (d >= a)
            {
                cout << rez;
                return 0;
            }
        }

        if (den % 2 == 1)
        {
            d -= c;
            den++;
        }
    }
    cout << rez;

    return 0;
}