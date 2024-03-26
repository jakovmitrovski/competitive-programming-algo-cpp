#include <bits/stdc++.h>

using namespace std;

int n;

long long dp[21][21][21][21];

long long solve(int curr, int positive, int negative, int combined)
{
    if (curr == n)
        return 1;

    if (dp[curr][positive][negative][combined] != -1)
        return dp[curr][positive][negative][combined];

    dp[curr][positive][negative][combined] = solve(curr + 1, positive, negative, combined);

    if (positive > 0)
    {
        dp[curr][positive][negative][combined] += solve(curr + 1, positive - 1, negative, combined);
    }
    if (negative > 0)
    {
        dp[curr][positive][negative][combined] += solve(curr + 1, positive, negative - 1, combined);
    }
    if (positive > 0 && negative > 0 && combined > 0)
    {
        dp[curr][positive][negative][combined] += solve(curr + 1, positive - 1, negative - 1, combined - 1);
    }
    return dp[curr][positive][negative][combined];
}

int main()
{
    memset(dp, -1, sizeof dp);

    int x, y, k;

    cin >> n >> x >> y >> k;

    cout << solve(0, x, y, k);

    r