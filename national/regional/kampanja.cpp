#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, c;

    cin >> p >> c;

    vector<pair<int, int>> v;

    for (int i = 0; i < c; i++)
    {
        int a, b;

        cin >> a >> b;

        pair<int, int> p1;

        p1.first = b;
        p1.second = a;

        v.push_back(p1);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int dp[c + 2][p + 2], rez = 0;

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < c; i++)
    {
        int trosam = v[i].second;
        int dobivam = v[i].first;

        for (int j = p; j >= 0; j--)
        {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            if (j >= trosam)
            {
                int ke_imam = j - trosam + dobivam;

                dp[i + 1][ke_imam] = max(dp[i + 1][ke_imam], dp[i][j] + 1);
                rez = max(rez, dp[i + 1][ke_imam]);
            }
        }
    }

    cout << rez;

    return 0;
}