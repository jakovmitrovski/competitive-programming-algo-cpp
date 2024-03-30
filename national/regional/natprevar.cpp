#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int dp[100] = {0};

    dp[4] = dp[7] = 1;

    for (int i = 8; i <= 20; i++)
    {
        if (dp[i - 7] == 1)
            dp[i] = 1;

        else if (dp[i - 4] == 1)
            dp[i] = 1;
    }

    if (dp[n])
        cout << "DA";

    else
        cout << "NE";

    return 0;
}