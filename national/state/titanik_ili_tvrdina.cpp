#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y, v;
    cin >> n >> x >> y >> v;

    bool flag1 = false;
    bool flag2 = false;

    if (x % 2 == 0)
    {
        if (y % 2 == 0 && v == 0)
            flag1 = true;
        else if (y % 2 == 1 && v == 1)
            flag1 = true;
    }
    else
    {
        if (y % 2 == 0 && v == 1)
            flag1 = true;
        else if (y % 2 == 1 && v == 0)
            flag1 = true;
    }

    if (x + y >= n)
    {
        if (v == 0)
            flag2 = true;
    }
    else
    {
        if (v == 1)
            flag2 = true;
    }

    if (flag1 && flag2)
    {
        cout << 3 << endl;
    }
    else if (flag1)
    {
        cout << 1 << endl;
    }
    else if (flag2)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << 4 << endl;
    }

    return 0;
}