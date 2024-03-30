#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m;

    cin >> n >> m;

    if ((n * m) % 3 == 0)
    {
        cout << (n * m) / 3 << " " << (n * m) / 3 << " " << (n * m) / 3;

        return 0;
    }

    if ((n * m) % 3 == 1)
    {
        if (n % 3 != 1)
            cout << (n * m) / 3 << " " << (n * m) / 3 + 1 << " " << (n * m) / 3;

        else
            cout << (n * m) / 3 + 1 << " " << (n * m) / 3 << " " << (n * m) / 3;

        return 0;
    }

    if ((n * m) % 3 == 2)
    {
        cout << (n * m) / 3 + 1 << " " << (n * m) / 3 + 1 << " " << (n * m) / 3;

        return 0;
    }

    return 0;
}