#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int ans = 1 << 30;
int b1, b2, b3;

int dp[10001];

void res(int k, int a1, int a2, int a3)
{
    if (k < b1 && k < b2 && k < b3)
    {
        if (ans > k)
        {
            ans = k;
            v = {a1, a2, a3};
        }
        return;
    }

    if (dp[k] != -1)
        return;

    if (k >= b1)
    {
        res(k - b1, a1 + 1, a2, a3);
    }
    if (k >= b2)
    {
        res(k - b2, a1, a2 + 1, a3);
    }
    if (k >= b3)
    {
        res(k - b3, a1, a2, a3 + 1);
    }
    dp[k] = 1;
}

int main()
{

    int m;

    memset(dp, -1, sizeof(dp));

    cin >> b1 >> b2 >> b3 >> m;

    if (b1 > m && b2 > m && b3 > m)
    {
        cout << m << endl;
        cout << 0 << " " << 0 << " " << 0 << endl;
        return 0;
    }

    res(m, 0, 0, 0);

    cout << ans << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}