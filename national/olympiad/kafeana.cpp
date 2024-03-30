#include <bits/stdc++.h>

using namespace std;

int dist[303][303];
char mat[102][102];
int all;
int parent[303];
int edges[303][303];
int allP;

bool bfs(int s, int t)
{
    queue<int> q;
    bool visited[303];
    memset(visited, false, sizeof visited);

    q.push(s);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (t == curr)
            return true;

        for (int i = 0; i < 303; i++)
            if (edges[curr][i] > 0 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
                parent[i] = curr;
            }
    }
    return false;
}

bool fflow(int s, int t, int limit)
{

    for (int i = 0; i < all + 3; i++)
        for (int j = 0; j < all + 3; j++)
            edges[i][j] = (dist[i][j] <= limit && dist[i][j] > 0);

    int maxflow = 0;

    while (bfs(s, t))
    {
        int flow = 1 << 25;

        for (int u = t; u != s; u = parent[u])
            flow = min(flow, edges[parent[u]][u]);
        for (int u = t; u != s; u = parent[u])
        {
            edges[parent[u]][u] -= flow;
            edges[u][parent[u]] += flow;
        }

        maxflow += flow;
        memset(parent, 0, sizeof parent);
    }

    return maxflow == allP;
}

int main()
{

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int indP[n + 2][m + 2];
    int indM[n + 2][m + 2];
    all = 1;
    allP = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'P')
                indP[i][j] = all++, allP++;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'M')
                indM[i][j] = all++;
        }

    memset(dist, 0, sizeof dist);

    int ss = 0, tt = all + 2;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'P')
            {
                dist[ss][indP[i][j]] = 1;
            }
            if (mat[i][j] == 'M')
            {
                dist[indM[i][j]][tt] = 1;
            }
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 'P')
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                int a[n + 2][m + 2];
                memset(a, -1, sizeof a);
                while (!q.empty())
                {
                    pair<int, int> p = q.front();
                    q.pop();

                    if (mat[p.first][p.second] == 'M')
                    {
                        dist[indP[i][j]][indM[p.first][p.second]] = a[p.first][p.second];
                    }

                    for (int move = 0; move < 4; move++)
                    {
                        int nx = p.first + dx[move], ny = p.second + dy[move];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] != '#' && a[nx][ny] == -1)
                        {
                            a[nx][ny] = a[p.first][p.second] == -1 ? 1 : a[p.first][p.second] + 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }

    int lo = 0, hi = 1 << 25;

    int ans = 0;

    while (lo <= hi)
    {
        int mid = lo + hi >> 1;
        if (fflow(ss, tt, mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout << ans;
    return 0;
}