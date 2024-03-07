#include <bits/stdc++.h>

using namespace std;

long long dp[100];

long long f(int n)
{
    if (dp[n] != -1)
        return dp[n];

    long long rez = 0;

    if (n <= 2)
        return 1;

    for (int i = 3; i < n; i++)
        rez += f(n - i - 1);

    return dp[n] = f(n - 1) + rez + 1;
}

int main()
{
    int n;

    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << f(n) << endl;

    return 0;
}