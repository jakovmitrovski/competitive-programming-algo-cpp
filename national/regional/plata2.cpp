#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, d1, d2;
    cin >> a >> b >> c;
    if (b - a == 1 and c - b == 1)
    {
        cout << c + 1;
        return 0;
    }
    if (b / a == c / b and b / a != 1)
    {
        d1 = b / a;
        d2 = c * d1;
        cout << d2;
        return 0;
    }
    else
    {
        d1 = b - a;
        d2 = c + d1;
        cout << d2;
    }

    return 0;
}