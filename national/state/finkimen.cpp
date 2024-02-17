#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    int mat[n + 2][m + 2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    bool visited[n + 2][m + 2];

    memset(visited, false, sizeof(visited));

    int rez = 0;

    int x1, y1;

    for (int i1 = 1; i1 <= 30; i1++)

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {

                if (mat[i][j] == i1 and visited[i][j] == false)
                {
                    x1 = i;
                    y1 = j;

                    pair<int, int> par;

                    par.first = x1;
                    par.second = y1;

                    queue<pair<int, int>> q;

                    // cout << "pusta od " << x1 << " " << y1 << endl;

                    q.push(par);

                    visited[x1][y1] = true;

                    rez++;

                    while (!q.empty())
                    {
                        pair<int, int> p1;

                        p1 = q.front();

                        q.pop();

                        int x, y;

                        x = p1.first;
                        y = p1.second;

                        if (x > 0 and visited[x - 1][y] == false and mat[x - 1][y] >= mat[x][y])
                        {
                            pair<int, int> p;

                            p.first = x - 1;
                            p.second = y;

                            q.push(p);

                            visited[x - 1][y] = true;
                        }

                        if (x < n - 1 and visited[x + 1][y] == false and mat[x + 1][y] >= mat[x][y])
                        {
                            pair<int, int> p;

                            p.first = x + 1;
                            p.second = y;

                            q.push(p);

                            visited[x + 1][y] = true;
                        }

                        if (y > 0 and visited[x][y - 1] == false and mat[x][y - 1] >= mat[x][y])
                        {
                            pair<int, int> p;

                            p.first = x;
                            p.second = y - 1;

                            q.push(p);

                            visited[x][y - 1] = true;
                        }

                        if (y < m - 1 and visited[x][y + 1] == false and mat[x][y + 1] >= mat[x][y])
                        {
                            pair<int, int> p;

                            p.first = x;
                            p.second = y + 1;

                            q.push(p);

                            visited[x][y + 1] = true;
                        }
                    }
                }
            }

    cout << rez;

    return 0;
}