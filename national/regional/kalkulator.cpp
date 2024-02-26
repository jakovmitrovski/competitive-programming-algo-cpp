#include <bits/stdc++.h>

using namespace std;

int main()
{

    string cif;
    cin >> cif;

    bool available[10];
    memset(available, false, sizeof available);

    for (char i : cif)
        available[i - '0'] = true;

    set<int> all;

    int count[5001];
    memset(count, 0, sizeof count);

    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                for (int t = 0; t <= 9; t++)
                    if ((available[i] || i == 0) and (available[j] || (i == 0 && j == 0)) and
                        (available[k] || (i == 0 && j == 0 && k == 0)) and available[t])
                    {
                        int num = 1000 * i + 100 * j + 10 * k + t;
                        if (num <= 5000)
                        {
                            count[num] = 5;
                            if (i == 0)
                            {
                                count[num]--;
                                if (j == 0)
                                {
                                    count[num]--;
                                    if (k == 0)
                                        count[num]--;
                                }
                            }
                            all.insert(num);
                        }
                    }
    }

    int target;
    cin >> target;

    int dp[5001], dp_prod[5001];
    for (int &i : dp)
        i = 1 << 25;
    for (int &i : dp_prod)
        i = 1 << 25;

    for (auto x : all)
        dp_prod[x] = count[x] - 1, dp[x] = count[x] - 1;

    for (int sum = 1; sum <= target; sum++)
    {
        if (dp_prod[sum] < 1 << 25)
        {
            for (auto x : all)
            {
                int next = min(sum * x, 5000);
                dp_prod[next] = min(dp_prod[next], dp_prod[sum] + count[x]);
            }
        }
    }

    set<int> nall;
    for (auto x : all)
        nall.insert(x);
    for (int i = 0; i <= target; i++)
        if (dp_prod[i] != 1 << 25)
        {
            nall.insert(i);
            count[i] = dp_prod[i];
        }

    for (auto x : nall)
    {
        for (int sum = 1; sum <= target; sum++)
        {
            int next = min(sum + x, 5000);
            dp[next] = min(dp[next], min(dp[sum], dp_prod[sum]) + count[x] + 1);
        }
    }

    cout << min(dp[target], dp_prod[target]);

    return 0;
}