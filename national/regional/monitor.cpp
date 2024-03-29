#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int m, n, k, p;

    cin >> m >> n >> k >> p;

    int ver[n + 2];
    int hor[m + 2];

    memset(ver, 0, sizeof(ver));
    memset(hor, 0, sizeof(hor));

    for (int i = 0; i < p; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        x--;
        y--;
        if (t == 1)
            hor[x] = -1;
        else
            ver[y] = -1;
    }

    if (ver[0] == -1)
        ver[0] = 1;
    else
        ver[0] = 0;

    for (int i = 1; i < n; i++)
        if (ver[i] == -1)
            ver[i] = ver[i - 1] + 1;
        else
            ver[i] = ver[i - 1];

    if (hor[0] == -1)
        hor[0] = 1;
    else
        hor[0] = 0;

    for (int i = 1; i < m; i++)
        if (hor[i] == -1)
            hor[i] = hor[i - 1] + 1;
        else
            hor[i] = hor[i - 1];

    int najmalku = 999999;

    for (int i = 0; i <= m - k; i++)
        for (int j = 0; j <= n - k; j++)
        {
            int verlinii = ver[j + k - 1];
            if (j != 0)
                verlinii -= ver[j - 1];
            int horlinii = hor[i + k - 1];
            if (i != 0)
                horlinii -= hor[i - 1];
            najmalku = min(najmalku, horlinii + verlinii);
        }

    cout << najmalku;

    return 0;
}