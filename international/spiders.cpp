#include <bits/stdc++.h>

using namespace std;

int dp[1001][11][1001];
int n, k, s;

int res(int second, int pos, int moves, int a[])
{
    if (second == s + 1)
    {
        return 0;
    }

    if (dp[second][pos][moves] != -1)
        return dp[second][pos][moves];

    int x = res(second + 1, pos, moves, a);
    int y = 0;
    if (pos < n - 1 && moves > 0)
        y = res(second + 1, pos + 1, moves - 1, a);
    int z = 0;
    if (pos > 0 && moves > 0)
        z = res(second + 1, pos - 1, moves - 1, a);

    int ans = max(x, max(y, z));

    if (pos == a[second - 1])
        ans++;

    return dp[second][pos][moves] = ans;
}

int solve()
{

    cin >> n >> k >> s;
    int a[s + 2];

    for (int i = 0; i < s; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    memset(dp, -1, sizeof dp);

    int x = res(1, 0, k, a);
    int y = 0;
    if (k > 0)
        y = res(1, 1, k - 1, a);

    return max(x, y);
}

int main()
{

    int tt;

    cin >> tt;

    while (tt--)
    {
        cout << solve() << endl;
    }

    return 0;
}