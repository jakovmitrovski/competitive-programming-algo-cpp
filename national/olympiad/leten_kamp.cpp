#include <bits/stdc++.h>

using namespace std;

int dp[20][(1 << 16) + 1];
int dist[22][22];
int k;

int tsp(int mask, int city, int done)
{
    if (mask == done)
        return dist[city][0];

    if (dp[city][mask] != -1)
        return dp[city][mask];

    int rez = 999999;

    for (int i = 0; i <= k; i++)
        if ((mask & (1 << i)) == 0)
            rez = min(rez, dist[city][i] + tsp(mask | (1 << i), i, done));

    return dp[city][mask] = rez;
}

int main()
{
    int n, m;
    cin >> n >> k >> m;

    vector<pair<int, int>> citiestovisit;
    citiestovisit.push_back({0, 0});

    for (int i = 1; i <= k; i++)
    {
        int a;
        cin >> a;
        citiestovisit.push_back({a, i});
    }

    vector<vector<pair<int, int>>> v(100000);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 0; i <= k; i++)
        for (int j = i + 1; j <= k; j++)
        {
            priority_queue<pair<int, int>> pq;
            int dp[100000];
            bool visited[100000];
            memset(visited, false, sizeof(visited));
            for (int t = 0; t <= n; t++)
                dp[t] = 9999999;
            pq.push({0, citiestovisit[i].first});
            dp[citiestovisit[i].first] = 0;
            while (!pq.empty())
            {
                pair<int, int> p = pq.top();
                pq.pop();
                int cost = -p.first, city = p.second;

                if (visited[city])
                    continue;

                visited[city] = true;

                for (int t = 0; t < v[city].size(); t++)
                    if (dp[v[city][t].first] > dp[city] + v[city][t].second)
                    {
                        dp[v[city][t].first] = dp[city] + v[city][t].second;
                        pq.push({-dp[v[city][t].first], v[city][t].first});
                    }
            }

            dist[i][j] = dp[citiestovisit[j].first];
            dist[j][i] = dp[citiestovisit[j].first];
        }

    memset(dp, -1, sizeof(dp));
    cout << tsp(1, 0, (1 << (k + 1)) - 1);

    return 0;
}
