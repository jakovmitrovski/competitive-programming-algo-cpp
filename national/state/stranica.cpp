#include <bits/stdc++.h>

using namespace std;

int main()
{

    int p, n;
    cin >> p >> n;

    int a[11];
    bool vis[11];
    memset(vis, false, sizeof vis);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        vis[a[i]] = true;
    }

    int ans = 1 << 25;

    ans = min(ans, p - 100);

    int c = 0;
    while (c <= p)
    {
        int br = 0;

        int x = c;
        bool flag = true;
        while (x > 0)
        {
            int last = x % 10;
            if (vis[last])
            {
                flag = false;
                break;
            }
            br++;
            x /= 10;
        }

        if (flag)
            ans = min(ans, br + p - c);
        c++;
    }

    int k = 1000000;

    while (k > p)
    {
        int br = 0;

        int x = k;
        bool flag = true;
        while (x > 0)
        {
            int last = x % 10;
            if (vis[last])
            {
                flag = false;
                break;
            }
            br++;
            x /= 10;
        }

        if (flag)
            ans = min(ans, br + k - p);
        k--;
    }

    cout << ans << endl;

    return 0;
}