#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    char mat[n + 2][m + 2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    int startx, starty;
    queue<pair<int, int>> q;
    vector<pair<int, int>> cuvari;
    bool visited[n + 2][n + 2];
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'G')
                cuvari.push_back(make_pair(i, j));

            if (mat[i][j] == 'R')
            {
                startx = i;
                starty = j;
            }
        }

    int cekori[n + 2][m + 2];

    memset(cekori, -1, sizeof(cekori));

    for (int i = 0; i < cuvari.size(); i++)
    {
        q.push(cuvari[i]);
        visited[cuvari[i].first][cuvari[i].second] = true;
        cekori[cuvari[i].first][cuvari[i].second] = 0;
    }

    int najmalce = 1;

    while (!q.empty())
    {
        pair<int, int> p = q.front();

        q.pop();

        int x = p.first, y = p.second;

        if (x > 0 and visited[x - 1][y] == false and mat[x - 1][y] != '*')
        {
            visited[x - 1][y] = true;
            q.push(make_pair(x - 1, y));
            cekori[x - 1][y] = cekori[x][y] + 1;
            if (cekori[x - 1][y] == najmalce)
                najmalce++;
        }

        if (x < n - 1 and visited[x + 1][y] == false and mat[x + 1][y] != '*')
        {
            visited[x + 1][y] = true;
            q.push(make_pair(x + 1, y));
            cekori[x + 1][y] = cekori[x][y] + 1;
            if (cekori[x + 1][y] == najmalce)
                najmalce++;
        }

        if (y > 0 and visited[x][y - 1] == false and mat[x][y - 1] != '*')
        {
            visited[x][y - 1] = true;
            q.push(make_pair(x, y - 1));
            cekori[x][y - 1] = cekori[x][y] + 1;
            if (cekori[x][y - 1] == najmalce)
                najmalce++;
        }

        if (y < m - 1 and visited[x][y + 1] == false and mat[x][y + 1] != '*')
        {
            visited[x][y + 1] = true;
            q.push(make_pair(x, y + 1));
            cekori[x][y + 1] = cekori[x][y] + 1;
            if (cekori[x][y + 1] == najmalce)
                najmalce++;
        }
    }

    /*for (int k=0; k<n; k++)
    {
        for (int j=0; j<m; j++) printf("%2d", cekori[k][j]);
        cout << endl;
    }*/

    for (int i = najmalce; i > 1; i--)
    {
        if (cekori[startx][starty] < i)
            continue;

        memset(visited, false, sizeof(visited));

        q.push(make_pair(startx, starty));
        visited[startx][starty] = true;

        while (!q.empty())
        {
            pair<int, int> p = q.front();

            q.pop();

            int x = p.first, y = p.second;

            if (mat[x][y] == 'Z')
            {
                cout << i;
                return 0;
            }

            if (x > 0 and visited[x - 1][y] == false and cekori[x - 1][y] >= i and mat[x - 1][y] != '*')
            {
                q.push(make_pair(x - 1, y));
                visited[x - 1][y] = true;
            }

            if (x < n - 1 and visited[x + 1][y] == false and cekori[x + 1][y] >= i and mat[x + 1][y] != '*')
            {
                q.push(make_pair(x + 1, y));
                visited[x + 1][y] = true;
            }

            if (y > 0 and visited[x][y - 1] == false and cekori[x][y - 1] >= i and mat[x][y - 1] != '*')
            {
                q.push(make_pair(x, y - 1));
                visited[x][y - 1] = true;
            }

            if (y < m - 1 and visited[x][y + 1] == false and cekori[x][y + 1] >= i and mat[x][y + 1] != '*')
            {
                q.push(make_pair(x, y + 1));
                visited[x][y + 1] = true;
            }
        }
    }

    return 0;
}