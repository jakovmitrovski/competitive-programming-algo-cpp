#include <iostream>

using namespace std;

int main()
{
    int n, p;

    cin >> n >> p;

    n = 2 * n - 2;

    int x = n + 1, y = n + 1, z = n + 1;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                if (3 * i + j == p and i + j + k == n && k < z)
                {
                    x = i;
                    y = j;
                    z = k;
                }

    cout << x << " " << y << " " << z;

    return 0;
}