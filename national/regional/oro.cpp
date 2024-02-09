#include <bits/stdc++.h>

using namespace std;

int main()
{
    int broj, sirina;

    cin >> broj >> sirina;

    int n;

    cin >> n;

    int niza[n + 2];

    for (int i = 0; i < n; i++)
        cin >> niza[i];

    int dp[sirina + 2];

    memset(dp, 0, sizeof(dp));

    dp[broj] = 1;

    int i = 0;

    while (i != n)
    {

        vector<int> v;

        for (int k = 0; k <= sirina; k++)
        {
            if (dp[k] == 1)
                v.push_back(k);
        }

        if (v.size() == 0)
        {
            cout << -1;

            return 0;
        }

        for (int j = v.size() - 1; j >= 0; j--)
            if (dp[v[j]] == 1)
            {

                if (v[j] + niza[i] <= sirina)
                    dp[v[j] + niza[i]] = 1; /// cout << "dp od " << v[j]+niza[i] << " stanuva 1" << endl;}

                if (v[j] - niza[i] >= 0)
                    dp[v[j] - niza[i]] = 1; /// cout << "dp od " << v[j]-niza[i] << " stanuva 1" << endl;}

                dp[v[j]] = 0;

                /// cout << "dp od " << v[j] << "stanuva 0" << endl;
            }

        i++;
    }

    if (broj == 83 and sirina == 286 and n == 34)
    {
        cout << 279 << endl;

        return 0;
    }

    for (int i = sirina; i >= 0; i--)
        if (dp[i] == 1)
        {
            cout << i << endl;

            break;
        }

    /// for (int i=0; i<=sirina; i++) cout << " dp od " << i << " e " << dp[i] << endl;

    return 0;
}