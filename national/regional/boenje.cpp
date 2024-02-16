#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int cena[1000][5], dp[1000][5];

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            cin >> cena[i][j];

    dp[1][0] = cena[1][0];
    dp[1][1] = 1000000000;
    dp[1][2] = 1000000000;

    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = cena[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);

    int pomos = min(dp[n][1], dp[n][2]);
    int rez = pomos;

    dp[1][1] = cena[1][1];
    dp[1][0] = 1000000000;
    dp[1][2] = 1000000000;

    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = cena[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);

    pomos = min(dp[n][0], dp[n][2]);
    rez = min(pomos, rez);

    dp[1][2] = cena[1][2];
    dp[1][0] = 1000000000;
    dp[1][1] = 1000000000;

    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = cena[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);

    pomos = min(dp[n][0], dp[n][1]);
    rez = min(pomos, rez);

    cout << rez << endl;

    return 0;
}