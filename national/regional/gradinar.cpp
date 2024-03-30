#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

int main()
{

    int n, m, r;

    cin >> n >> m >> r;

    char mat[n + 2][m + 2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    bool visited1[n + 2][m + 2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited1[i][j] = false;

    int kolku_fakja[n + 2][m + 2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            kolku_fakja[i][j] = 0;

    pair<int, int> par2;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'C')
            {
                par2.first = i;
                par2.second = j;

                v.push_back(par2);
            }
        }

    for (int i = 0; i < v.size(); i++)

        if (mat[v[i].first][v[i].second] == 'C' and visited1[v[i].first][v[i].second] == false)
        {
            bool visited[n + 2][m + 2];

            memset(visited, 0, sizeof(visited));

            int cekori[n + 2][m + 2];

            memset(cekori, 0, sizeof(cekori));

            pair<int, int> par;

            par.first = v[i].first;
            par.second = v[i].second;

            queue<pair<int, int>> q;

            q.push(par);

            visited1[v[i].first][v[i].second] = true;

            while (!q.empty())
            {
                pair<int, int> p1;

                p1 = q.front();

                q.pop();

                int x, y;

                x = p1.first;
                y = p1.second;

                if (cekori[x][y] > r)
                    continue;

                if (x > 0 and mat[x - 1][y] != '#' and visited[x - 1][y] == false and cekori[x][y] + 1 <= r)
                {

                    visited[x - 1][y] = true;

                    pair<int, int> p;

                    p.first = x - 1;
                    p.second = y;

                    cekori[x - 1][y] += cekori[x][y] + 1;

                    q.push(p);

                    if (mat[x - 1][y] != 'C')
                        kolku_fakja[x - 1][y]++;
                }

                if (x < n - 1 and mat[x + 1][y] != '#' and visited[x + 1][y] == false and cekori[x][y] + 1 <= r)
                {

                    visited[x + 1][y] = true;

                    pair<int, int> p;

                    p.first = x + 1;
                    p.second = y;

                    cekori[x + 1][y] += cekori[x][y] + 1;

                    q.push(p);

                    if (mat[x + 1][y] != 'C')
                        kolku_fakja[x + 1][y]++;
                }

                if (y > 0 and mat[x][y - 1] != '#' and visited[x][y - 1] == false and cekori[x][y] + 1 <= r)
                {

                    visited[x][y - 1] = true;

                    pair<int, int> p;

                    p.first = x;
                    p.second = y - 1;

                    cekori[x][y - 1] += cekori[x][y] + 1;

                    q.push(p);

                    if (mat[x][y - 1] != 'C')
                        kolku_fakja[x][y - 1]++;
                }

                if (y < m - 1 and mat[x][y + 1] != '#' and visited[x][y + 1] == false and cekori[x][y] + 1 <= r)
                {

                    visited[x][y + 1] = true;

                    pair<int, int> p;

                    p.first = x;
                    p.second = y + 1;

                    cekori[x][y + 1] += cekori[x][y] + 1;

                    q.push(p);

                    if (mat[x][y + 1] != 'C')
                        kolku_fakja[x][y + 1]++;
                }
            }
        }

    int najgolem = kolku_fakja[0][0];

    int rezx, rezy;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (kolku_fakja[i][j] > najgolem)
            {
                najgolem = kolku_fakja[i][j];

                rezx = i;
                rezy = j;
            }

    cout << rezx + 1 << " " << rezy + 1;

    return 0;
}