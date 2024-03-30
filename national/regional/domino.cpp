#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int dp[n + 2] = {0};

    dp[0] = 3;

    int k = 3;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + k;
        k++;
    }

    cout << dp[n - 1] * n;

    return 0;
}