#include <bits/stdc++.h>

using namespace std;

int dp[30001][4];
vector<int> v;

int res(int ind, int last)
{

    if (ind == v.size())
        return 0;

    if (dp[ind][last] != -1)
        return dp[ind][last];

    int ans = 1 << 25;

    for (int i = last; i <= 3; i++)
        if (v[ind] == i)
            ans = min(ans, res(ind + 1, i));
        else
            ans = min(ans, 1 + res(ind + 1, i));

    return dp[ind][last] = ans;
}

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    memset(dp, -1, sizeof dp);

    int left = res(0, 1);

    memset(dp, -1, sizeof dp);

    reverse(v.begin(), v.end());

    int right = res(0, 1);

    cout << min(left, right);

    return 0;
}