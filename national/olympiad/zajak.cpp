#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    int MAT[N][M];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> MAT[i][j];

    int dp[N][M];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = MAT[0][0];

    for (int j = 1; j < M; j++)
        dp[1][j] = MAT[0][0] + MAT[0][j] + MAT[1][j];

    for (int i = 1; i + 1 < N; i++)
    {
        int max1 = 0, max2 = 0;
        for (int j = 0; j < M; j++)
        {
            if (dp[i][j] >= max1)
            {
                max2 = max1;
                max1 = dp[i][j];
            }
            else if (dp[i][j] > max2)
            {
                max2 = dp[i][j];
            }
        }

        for (int j = 0; j < M; j++)
        {

            int max_value = max1;
            if (dp[i][j] == max1)
            {

                max_value = max2;
            }

            dp[i + 1][j] = max(dp[i + 1][j], max_value + MAT[i][j] + MAT[i + 1][j]);
        }
    }

    for (int j = 0; j + 1 < M; j++)
        dp[N - 1][M - 1] = max(dp[N - 1][M - 1], dp[N - 1][j] + MAT[N - 1][M - 1]);

    cout << dp[N - 1][M - 1] << endl;
    return 0;
}