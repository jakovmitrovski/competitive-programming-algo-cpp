#include <iostream>

using namespace std;

int main()
{

    string s;

    cin >> s;

    int dp[252] = {0};

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != '0')
            dp[i + 1] = dp[i];

        if ((s[i - 1] == '1') or (s[i - 1] == '2' and s[i] <= '6'))
            dp[i + 1] += dp[i - 1];
    }

    cout << dp[s.size()];

    return 0;
}