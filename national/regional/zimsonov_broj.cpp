#include <iostream>

using namespace std;

bool zimsonov(int a)
{
    int broj = a, palindrom = 0;

    while (broj > 0)
    {
        int b = broj % 10;
        palindrom = 10 * palindrom + b;
        broj /= 10;
    }

    if (a == palindrom)
        return true;

    broj = a;

    while (broj > 0)
    {
        int b = broj % 10;

        if (b == 0 || a % b != 0)
            return false;

        broj /= 10;
    }

    return true;
}

int main()
{
    int n, m;

    cin >> n >> m;

    int rez = 0;

    for (int i = n; i <= m; i++)
        if (zimsonov(i) == true)
            rez++;

    cout << rez;

    return 0;
}