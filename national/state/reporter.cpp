#include <bits/stdc++.h>

using namespace std;

int nx[50002];
bool vis[50002];
int ans = 0;

void dfs(int node, int cnt)
{
    if (vis[node])
    {
        ans = max(ans, cnt);
        return;
    }

    vis[node] = true;
    dfs(nx[node], cnt + 1);
}

int main()
{
    int n;

    cin >> n;

    int in_deg[50002];
    memset(in_deg, 0, sizeof in_deg);

    for (int i = 0; i < n; i++)
    {
        cin >> nx[i];
        nx[i]--;
        in_deg[nx[i]] = 1;
    }

    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i, 0);

    memset(vis, false, sizeof vis);

    for (int i = 0; i < n; i++)
        if (!in_deg[i])
        {
            dfs(i, 0);
            memset(vis, false, sizeof vis);
        }

    cout << ans;

    return 0;
}