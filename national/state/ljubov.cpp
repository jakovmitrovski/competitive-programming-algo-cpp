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

    bool visited[n + 2][m + 2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;

    int cekori[n + 2][m + 2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cekori[i][j] = -1;

    int x1, y1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'S')
            {
                x1 = i;
                y1 = j;
            }
        }

    pair<int, int> p1;

    p1.first = x1;
    p1.second = y1;

    queue<pair<int, int>> q;

    q.push(p1);

    visited[x1][y1] = true;

    cekori[x1][y1] = 0;

    while (!q.empty())
    {
        pair<int, int> par;

        par = q.front();

        q.pop();

        int x, y;

        x = par.first;
        y = par.second;

        if (mat[x][y] == 'E')
        {
            cout << cekori[x][y];

            return 0;
        }

        if (x > 0 and mat[x - 1][y] != '#' and visited[x - 1][y] == false)
        {
            visited[x - 1][y] = true;

            pair<int, int> p;

            p.first = x - 1;
            p.second = y;

            q.push(p);

            cekori[x - 1][y] = cekori[x][y] + 1;
        }

        if (x < n - 1 and mat[x + 1][y] != '#' and visited[x + 1][y] == false)
        {
            visited[x + 1][y] = true;

            pair<int, int> p;

            p.first = x + 1;
            p.second = y;

            q.push(p);

            cekori[x + 1][y] = cekori[x][y] + 1;
        }

        if (y > 0 and mat[x][y - 1] != '#' and visited[x][y - 1] == false)
        {
            visited[x][y - 1] = true;

            pair<int, int> p;

            p.first = x;
            p.second = y - 1;

            q.push(p);

            cekori[x][y - 1] = cekori[x][y] + 1;
        }

        if (y < m - 1 and mat[x][y + 1] != '#' and visited[x][y + 1] == false)
        {
            visited[x][y + 1] = true;

            pair<int, int> p;

            p.first = x;
            p.second = y + 1;

            q.push(p);

            cekori[x][y + 1] = cekori[x][y] + 1;
        }
    }

    int cekori1[n + 2][m + 2], cekori2[n + 2][m + 2];

    bool visited1[n + 2][m + 2], visited2[n + 2][m + 2];

    memset(cekori1, -1, sizeof(cekori1));
    memset(cekori2, -1, sizeof(cekori2));

    memset(visited1, false, sizeof(visited1));
    memset(visited2, false, sizeof(visited2));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'S')
            {
                pair<int, int> p2;

                p2.first = i;
                p2.second = j;

                q.push(p2);

                cekori1[i][j] = 0;

                visited1[i][j] = true;

                break;
            }
        }

    while (!q.empty())
    {
        pair<int, int> par;

        par = q.front();

        q.pop();

        int x, y;

        x = par.first;
        y = par.second;

        if (x > 0 and mat[x - 1][y] != '#' and visited1[x - 1][y] == false)
        {
            pair<int, int> p;

            p.first = x - 1;
            p.second = y;

            q.push(p);

            cekori1[x - 1][y] = cekori1[x][y] + 1;

            visited1[x - 1][y] = true;
        }

        if (x < n - 1 and mat[x + 1][y] != '#' and visited1[x + 1][y] == false)
        {
            pair<int, int> p;

            p.first = x + 1;
            p.second = y;

            q.push(p);

            cekori1[x + 1][y] = cekori1[x][y] + 1;

            visited1[x + 1][y] = true;
        }

        if (y > 0 and mat[x][y - 1] != '#' and visited1[x][y - 1] == false)
        {
            pair<int, int> p;

            p.first = x;
            p.second = y - 1;

            q.push(p);

            cekori1[x][y - 1] = cekori1[x][y] + 1;

            visited1[x][y - 1] = true;
        }

        if (y < m - 1 and mat[x][y + 1] != '#' and visited1[x][y + 1] == false)
        {
            pair<int, int> p;

            p.first = x;
            p.second = y + 1;

            q.push(p);

            cekori1[x][y + 1] = cekori1[x][y] + 1;

            visited1[x][y + 1] = true;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 'E')
            {
                pair<int, int> p2;

                p2.first = i;
                p2.second = j;

                q.push(p2);

                cekori2[i][j] = 0;
                visited2[i][j] = true;

                break;
            }

    while (!q.empty())
    {
        pair<int, int> par;

        par = q.front();

        q.pop();

        int x, y;

        x = par.first;
        y = par.second;

        if (x > 0 and mat[x - 1][y] != '#' and visited2[x - 1][y] == false)
        {
            pair<int, int> p;

            p.first = x - 1;
            p.second = y;

            q.push(p);

            cekori2[x - 1][y] = cekori2[x][y] + 1;

            visited2[x - 1][y] = true;
        }

        if (x < n - 1 and mat[x + 1][y] != '#' and visited2[x + 1][y] == false)
        {
            pair<int, int> p;

            p.first = x + 1;
            p.second = y;

            q.push(p);

            cekori2[x + 1][y] = cekori2[x][y] + 1;

            visited2[x + 1][y] = true;
        }

        if (y > 0 and mat[x][y - 1] != '#' and visited2[x][y - 1] == false)
        {
            pair<int, int> p;

            p.first = x;
            p.second = y - 1;

            q.push(p);

            cekori2[x][y - 1] = cekori2[x][y] + 1;

            visited2[x][y - 1] = true;
        }

        if (y < m - 1 and mat[x][y + 1] != '#' and visited2[x][y + 1] == false)
        {
            pair<int, int> p;

            p.first = x;
            p.second = y + 1;

            q.push(p);

            cekori2[x][y + 1] = cekori2[x][y] + 1;

            visited2[x][y + 1] = true;
        }
    }

    vector<int> v;

    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < m - 1; j++)
            if (mat[i][j] == '#')
            {
                if (visited1[i + 1][j] == true and visited2[i - 1][j] == true)
                {
                    int c = cekori1[i + 1][j] + cekori2[i - 1][j];

                    v.push_back(c);

                    /// cout << "vlaga 1";
                }

                if (visited1[i][j + 1] == true and visited2[i][j - 1] == true)
                {
                    int c = cekori1[i][j + 1] + cekori2[i][j - 1];

                    v.push_back(c);

                    /// cout << "vlaga 2";
                }

                if (visited1[i - 1][j] == true and visited2[i][j - 1] == true)
                {
                    int c = cekori1[i - 1][j] + cekori2[i][j - 1];

                    v.push_back(c);

                    /// cout << "vlaga 3";
                }

                if (visited1[i][j - 1] == true and visited2[i + 1][j] == true)
                {
                    int c = cekori1[i][j - 1] + cekori2[i + 1][j];

                    v.push_back(c);

                    /// cout << "vlaga 4";
                }

                if (visited1[i + 1][j] == true and visited2[i][j + 1] == true)
                {
                    int c = cekori1[i + 1][j] + cekori2[i][j + 1];

                    v.push_back(c);

                    /// cout << "vlaga 5";
                }

                if (visited1[i][j + 1] == true and visited2[i - 1][j] == true)
                {
                    int c = cekori1[i][j + 1] + cekori2[i - 1][j];

                    v.push_back(c);

                    /// cout << "vlaga 6";
                }

                if (visited2[i + 1][j] == true and visited1[i - 1][j] == true)
                {
                    int c = cekori2[i + 1][j] + cekori1[i - 1][j];

                    v.push_back(c);

                    /// cout << "vlaga 7";
                }

                if (visited2[i][j + 1] == true and visited1[i][j - 1] == true)
                {
                    int c = cekori2[i][j + 1] + cekori1[i][j - 1];

                    v.push_back(c);

                    /// cout << "vlaga 8";
                }

                if (visited2[i - 1][j] == true and visited1[i][j - 1] == true)
                {
                    int c = cekori2[i - 1][j] + cekori1[i][j - 1];

                    v.push_back(c);

                    /// cout << "vlaga 9 za " << i << " " << j;
                }

                if (visited2[i][j - 1] == true and visited1[i + 1][j] == true)
                {
                    int c = cekori2[i][j - 1] + cekori1[i + 1][j];

                    v.push_back(c);

                    /// cout << "vlaga 10";
                }

                if (visited2[i + 1][j] == true and visited1[i][j + 1] == true)
                {
                    int c = cekori2[i + 1][j] + cekori1[i][j + 1];

                    v.push_back(c);

                    /// cout << "vlaga 11";
                }

                if (visited2[i][j + 1] == true and visited1[i - 1][j] == true)
                {
                    int c = cekori2[i][j + 1] + cekori1[i - 1][j];

                    v.push_back(c);

                    /// cout << "vlaga 12";
                }
            }

    if (v.size() == 0)
    {
        cout << -1;

        return 0;
    }

    sort(v.begin(), v.end());

    cout << v[v.size() - 1] + 2 << endl;

    return 0;
}