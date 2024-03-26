#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    int barani;

    cin >> barani;

    bool visited[n + 100][m + 100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;

    int cekori[n + 100][m + 100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cekori[i][j] = -1;

    int k;

    cin >> k;

    int br = 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < k; i++)
    {
        int a, b;

        pair<int, int> par3;

        cin >> a >> b;

        a--;

        b--;

        par3.first = a;
        par3.second = b;

        visited[a][b] = true;

        cekori[a][b] = 0;

        br++;

        q.push(par3);
    }

    int posledena_vo_barok = 0;

    while (br < barani)
    {

        pair<int, int> par;

        par = q.front();

        q.pop();

        int x, y;

        x = par.first;
        y = par.second;

        if (x > 0 and visited[x - 1][y] == false)
        {
            visited[x - 1][y] = true;

            pair<int, int> p;

            p.first = x - 1;
            p.second = y;

            q.push(p);

            cekori[x - 1][y] = cekori[x][y] + 1;

            br++;

            posledena_vo_barok = cekori[x - 1][y];
        }

        if (x < n - 1 and visited[x + 1][y] == false)
        {
            visited[x + 1][y] = true;

            pair<int, int> p;

            p.first = x + 1;
            p.second = y;

            q.push(p);

            cekori[x + 1][y] = cekori[x][y] + 1;

            br++;

            posledena_vo_barok = cekori[x + 1][y];
        }

        if (y > 0 and visited[x][y - 1] == false)
        {
            visited[x][y - 1] = true;

            pair<int, int> p;

            p.first = x;
            p.second = y - 1;

            q.push(p);

            cekori[x][y - 1] = cekori[x][y] + 1;

            br++;

            posledena_vo_barok = cekori[x][y - 1];
        }

        if (y < m - 1 and visited[x][y + 1] == false)
        {
            visited[x][y + 1] = true;

            pair<int, int> p;

            p.first = x;
            p.second = y + 1;

            q.push(p);

            cekori[x][y + 1] = cekori[x][y] + 1;

            br++;

            posledena_vo_barok = cekori[x][y + 1];
        }
    }

    cout << posledena_vo_barok;

    return 0;
}