#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> vec1(101);
vector<vector<pair<int, int>>> v(101);
int n, x, k, l, m;
bool vis[101];
int steps[101];
int dp[101][9][451][2];

int res(int city, int left_usages, int left_kilometers, bool active)
{

    if (city == n)
        return 0;

    int ans = 1 << 25;

    if (city <= x && active)
    {
        active = false;
        left_kilometers = l;
    }

    if (dp[city][left_usages][left_kilometers][active] != -1)
        return dp[city][left_usages][left_kilometers][active];

    for (int i = 0; i < v[city].size(); i++)
    {
        int next = v[city][i].first, cost = v[city][i].second;

        if (vis[next])
            continue;

        vis[next] = true;

        if (active && left_kilometers >= cost)
            ans = min(ans, res(next, left_usages, left_kilometers - cost, true));

        if (left_usages > 0 && l >= cost)
            ans = min(ans, res(next, left_usages - 1, l - cost, true));

        ans = min(ans, cost + res(next, left_usages, l, false));

        vis[next] = false;
    }

    return dp[city][left_usages][left_kilometers][active] = ans;
}

int main()
{

    cin >> n >> x >> k >> l >> m;
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
        vec1[a].push_back({b, c});
        vec1[b].push_back({a, c});
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});

    for (int i = 0; i <= n; i++)
        steps[i] = 1 << 25;

    steps[1] = 0;

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int dist = -curr.first, city = curr.second;

        vis[city] = true;

        for (auto neigh : vec1[city])
        {
            if (!vis[neigh.first] && steps[neigh.first] > steps[city] + neigh.second)
            {
                pq.push({-(dist + neigh.second), neigh.first});
                steps[neigh.first] = steps[city] + neigh.second;
            }
        }
    }

    for (auto edge : edges)
    {
        int cost = edge.first, to = edge.second.first, from = edge.second.second;

        if (from == n || to == 0)
            v[to].push_back({from, cost});
        else if (to == n || from == 0)
            v[from].push_back({to, cost});
        else
        {
            if (steps[from] <= steps[to])
                v[from].push_back({to, cost});
            else
                v[to].push_back({from, cost});
        }
    }

    memset(dp, -1, sizeof dp);
    memset(vis, false, sizeof vis);

    vis[1] = true;

    int ans = res(1, k, l, false);

    cout << ans;

    return 0;
}