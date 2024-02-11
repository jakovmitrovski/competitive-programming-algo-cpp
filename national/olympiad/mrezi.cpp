#include <bits/stdc++.h>

using namespace std;

vector<int> res;

bool solve()
{

    int n, k;

    cin >> n >> k;

    vector<pair<int, pair<int, int>>> edges;

    vector<int> first;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            int a;
            cin >> a;
            edges.push_back({a, {i, i + j}});
            if (i == 1)
                first.push_back(a);
        }
    }

    int dist[n + 1][n + 1], dist1[n + 1][n + 1];
    for (int j = 0; j <= n; j++)
        for (int i = 0; i <= n; i++)
        {
            if (i != j)
                dist[i][j] = 1 << 25, dist1[i][j] = 1 << 25;
            else
                dist[i][j] = 0, dist1[i][j] = 0;
        }

    for (auto edge : edges)
    {
        int cost = edge.first, from = edge.second.first, to = edge.second.second;
        dist[from][to] = cost;
        dist[to][from] = cost;
    }

    for (int q = 1; q <= n; q++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i != q && q != j)
                    dist1[i][j] = min(dist1[i][j], min(dist[i][q] + dist[q][j], dist1[i][q] + dist1[q][j]));
            }

    int must = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (dist1[i][j] > dist[i][j])
                must += 1;
    }

    must /= 2;

    return must > k;
}

int main()
{

    int t;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        if (solve())
            res.push_back(i);
    }

    cout << res.size() << endl;
    for (auto x : res)
        cout << x << endl;

    return 0;
}