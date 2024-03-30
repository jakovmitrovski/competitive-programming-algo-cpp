#include <bits/stdc++.h>

using namespace std;

int dp[2001][3001];

struct Item
{
    int to, time, cost;
};

int main()
{
    int cash, n, m;

    cin >> cash >> n >> m;

    vector<vector<Item>> v(10000);

    for (int i = 0; i < m; i++)
    {
        int a, b, t, c;

        cin >> a >> b >> t >> c;
        Item it;
        it.to = b;
        it.cost = c;
        it.time = t;
        v[a].push_back(it);
        it.to = a;
        v[b].push_back(it);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= cash; j++)
            dp[j][i] = 99999999;

    dp[0][1] = 0;

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 1}});
    bool visited[cash + 1][n + 1];
    memset(visited, false, sizeof(visited));

    while (!pq.empty())
    {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();

        int time = -p.first, cost = p.second.first, city = p.second.second;
        visited[cost][city] = true;

        for (int i = 0; i < v[city].size(); i++)
            if (cost + v[city][i].cost <= cash && !visited[cost + v[city][i].cost][v[city][i].to] && dp[cost + v[city][i].cost][v[city][i].to] > time + v[city][i].time)
            {
                dp[cost + v[city][i].cost][v[city][i].to] = time + v[city][i].time;
                pq.push({-dp[cost + v[city][i].cost][v[city][i].to], {cost + v[city][i].cost, v[city][i].to}});
            }
    }
    int rez = 99999999;
    for (int i = 0; i <= cash; i++)
        rez = min(rez, dp[i][n]);

    if (rez == 99999999)
    {
        cout << -1;
    }
    else
        cout << rez;

    return 0;
}