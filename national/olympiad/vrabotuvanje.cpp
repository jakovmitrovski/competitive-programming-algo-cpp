#include <bits/stdc++.h>

using namespace std;

vector<pair<int, unsigned short>> applicants;

int dp[200][1 << 16];
int n;

bool isOn(unsigned short mask, unsigned short bit)
{
    return (mask & (1 << bit)) > 0;
}

int res(unsigned short last, unsigned short mask, unsigned short target)
{

    int ans = 1 << 25;

    if (mask == target)
        return 0;

    if (last == 200)
        return 1 << 25;

    if (dp[last][mask] != -1)
        return dp[last][mask];

    for (int i = last; i < applicants.size(); i++)
    {
        int cost = applicants[i].first;
        unsigned short app_mask = applicants[i].second;
        // cout << cost << " " << app_mask << endl;

        for (int j = n - 1; j >= 0; j--)
        {
            if (isOn(app_mask, j) && isOn(mask, j))
            {
                app_mask ^= (1 << j);
                app_mask |= (1 << (n + j));
            }
        }

        ans = min(ans, cost + res(i + 1, mask | app_mask, target));
    }

    return dp[last][mask] = ans;
}

int main()
{

    unsigned short m;
    cin >> n >> m;

    unsigned short target_mask = (1 << 2 * n) - 1, current_mask = 0;
    int starter_sum = 0;

    for (int i = 0; i < m; i++)
    {
        int cost;
        cin >> cost;
        starter_sum += cost;
        unsigned short t;
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            unsigned short a;
            cin >> a;
            if (!isOn(current_mask, a - 1))
                current_mask |= (1 << (a - 1));
            else
                current_mask |= (1 << (n + a - 1));
        }
    }

    if (current_mask == target_mask)
    {
        cout << starter_sum << endl;
        return 0;
    }

    unsigned short appl;
    cin >> appl;

    for (int i = 0; i < appl; i++)
    {
        int cost;
        unsigned short mask = 0;
        cin >> cost;
        int t;
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            unsigned short a;
            cin >> a;
            mask |= (1 << (a - 1));
        }
        applicants.push_back({cost, mask});
    }

    memset(dp, -1, sizeof dp);

    cout << starter_sum + res(0, current_mask, target_mask);

    return 0;
}