#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<set<int>> v;

    for (int i = 0; i <= n; i++)
        v.push_back({i});

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].insert(v[b].begin(), v[b].end());
        v[b].insert(v[a].begin(), v[a].end());
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
        ans = max(ans, (int)v[i].size());

    cout << ans - 1;

    return 0;
}