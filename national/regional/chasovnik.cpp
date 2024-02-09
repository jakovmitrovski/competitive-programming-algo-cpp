#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d;
    if (d >= b)
    {
        f = d - b;
        if (c < a)
            e = 24 - (a - c);
        else
            e = c - a;
    }
    else
    {
        f = 60 - (b - d);
        if (c <= a)
            e = 24 - (a - c) - 1;
        else
            e = c - a - 1;
    }
    if (e / 10 == 0)
        cout << "0" << e << ":";
    else
        cout << e << ":";
    if (f / 10 == 0)
        cout << "0" << f;
    else
        cout << f;
    return 0;
}