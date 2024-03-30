#include <bits/stdc++.h>

using namespace std;

int sreden(int a, int b, int c)
{
    if (b < a and c > a)
        return a;

    else if (c < a and b > a)
        return a;

    else if (a < b and c > b)
        return b;

    else if (c < b and a > b)
        return b;

    else
        return c;
}

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    if (a == b and b == c)
    {
        cout << 0;
        return 0;
    }

    int rez = 0;

    if (a == b or b == c or a == c)
    {
        if (a == b)
        {
            rez = abs(c - a) * 10;

            cout << rez;

            return 0;
        }

        if (b == c)
        {
            rez = abs(a - b) * 10;

            cout << rez;

            return 0;
        }

        if (a == c)
        {
            rez = abs(b - c) * 10;

            cout << rez;

            return 0;
        }
    }

    int d = sreden(a, b, c);

    if (d == a)
    {
        if (b > d)
        {
            rez += (b - d) * 10;
            rez += (d - c) * 10;

            cout << rez;

            return 0;
        }

        else
        {
            rez += (c - d) * 10;
            rez += (d - b) * 10;

            cout << rez;

            return 0;
        }
    }

    else if (d == b)
    {
        if (a > d)
        {
            rez += (a - d) * 10;
            rez += (d - c) * 10;

            cout << rez;

            return 0;
        }

        else
        {
            rez += (c - d) * 10;
            rez += (d - a) * 10;

            cout << rez;

            return 0;
        }
    }

    else
    {
        if (b > d)
        {
            rez += (b - d) * 10;
            rez += (d - a) * 10;

            cout << rez;

            return 0;
        }

        else
        {
            rez += (a - d) * 10;
            rez += (d - b) * 10;

            cout << rez;

            return 0;
        }
    }

    return 0;
}