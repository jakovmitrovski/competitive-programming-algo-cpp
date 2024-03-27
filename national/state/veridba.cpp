#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, n;
    cin >> x >> y >> n;

    if (x * y == n)
        cout << 0;

    else if (n % x == 0 && n / x <= y)
        cout << 1;

    else if (n % y == 0 && n / y <= x)
        cout << 1;

    else
    {

        int result = -1;
        int smaller = min(x, y);
        int larger = max(x, y);

        for (int s = 1; s <= smaller && s * s <= n; s++)
            if (n % s == 0)
            {
                int l = n / s;

                if (s <= smaller && l <= larger)
                    result = 2;
            }

        cout << result;
    }

    return 0;
}