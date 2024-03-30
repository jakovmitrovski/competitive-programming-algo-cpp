#include <bits/stdc++.h>

using namespace std;

int mat[352][352];
int parent[352];

int gcd(long long x, long long y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

bool exists(long long t)
{
    auto x = (long long)sqrt(t);
    x *= x;
    return x == t;
}

bool valid(long long x, long long y)
{
    return gcd(min(x, y), max(x, y)) == 1 && exists(x * x + y * y);
}

bool bfs(int s, int t)
{
    queue<int> q;

    q.push(s);

    bool visited[352];
    memset(visited, false, sizeof visited);
    memset(parent, -1, sizeof parent);
    parent[s] = s;
    visited[s] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == t)
            return true;

        for (int i = 0; i < 350; i++)
            if (!visited[i] && mat[curr][i] > 0)
            {
                parent[i] = curr;
                visited[i] = true;
                q.push(i);
            }
    }

    return false;
}

int fflow(int s, int t)
{

    int maxflow = 0;

    while (bfs(s, t))
    {
        for (int u = t; u != s; u = parent[u])
        {
            mat[parent[u]][u]--;
            mat[u][parent[u]]++;
        }
        maxflow++;
    }

    return maxflow;
}

int main()
{

    int n;
    cin >> n;

    int a[n + 2];

    memset(mat, 0, sizeof mat);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mat[0][i + 1] = 1;
        mat[i + n + 1][349] = 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && valid(a[i], a[j]))
                mat[i + 1][j + n + 1] = 1;

    cout << fflow(0, 349);
}