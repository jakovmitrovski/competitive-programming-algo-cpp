#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    int cekori[n + 2][m + 2];

    memset(cekori, -1, sizeof(cekori));

    int n1, m1;

    cin >> n1 >> m1;

    bool visited[n + 2][m + 2];

    memset(visited, false, sizeof(visited));

    cekori[n1][m1] = 0;

    visited[n1][m1] = true;

    queue<pair<int, int>> q;

    pair<int, int> p1;

    p1.first = n1;
    p1.second = m1;

    q.push(p1);

    while (!q.empty())
    {
        int x, y;

        pair<int, int> par;

        par = q.front();

        q.pop();

        x = par.first;
        y = par.second;

        if (x > 1 and visited[x - 1][y] == false)
        {
            visited[x - 1][y] = true;

            cekori[x - 1][y] = cekori[x][y] + 1;

            pair<int, int> p;

            p.first = x - 1;
            p.second = y;

            q.push(p);
        }

        if (x <= n - 1 and visited[x + 1][y] == false)
        {
            visited[x + 1][y] = true;

            cekori[x + 1][y] = cekori[x][y] + 1;

            pair<int, int> p;

            p.first = x + 1;
            p.second = y;

            q.push(p);
        }

        if (y > 1 and visited[x][y - 1] == false)
        {
            visited[x][y - 1] = true;

            cekori[x][y - 1] = cekori[x][y] + 1;

            pair<int, int> p;

            p.first = x;
            p.second = y - 1;

            q.push(p);
        }

        if (y <= m - 1 and visited[x][y + 1] == false)
        {
            visited[x][y + 1] = true;

            cekori[x][y + 1] = cekori[x][y] + 1;

            pair<int, int> p;

            p.first = x;
            p.second = y + 1;

            q.push(p);
        }
    }

    int najgolem = cekori[0][0];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (cekori[i][j] > najgolem)
                najgolem = cekori[i][j];

    int br = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (cekori[i][j] == najgolem)
                br++;

    cout << najgolem << endl;

    cout << br << endl;

    /*for (int i=1; i<=n; i++)
    {
        cout << endl;
        for (int j=1; j<=m; j++)

        cout << cekori[i][j] << " ";
    } */

    return 0;
}