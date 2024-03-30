#include <bits/stdc++.h>

using namespace std;

int main()
{

    int x, y;

    cin >> x >> y;

    int eX, eY;

    cin >> eX >> eY;

    if (x + y != eX + eY)
    {
        cout << -1;

        return 0;
    }

    bool visited[100001];

    memset(visited, false, sizeof(visited));

    int cekori[100001];

    memset(cekori, -1, sizeof(cekori));

    queue<int> q;

    q.push(x);

    visited[x] = true;

    cekori[x] = 0;

    while (!q.empty())
    {
        int teme = q.front();

        q.pop();

        int x1 = teme + 1;

        int x2 = (teme - 1 - ((2 * teme) % 31));

        if (x1 < 100001 and visited[x1] == false)
        {
            visited[x1] = true;

            cekori[x1] = cekori[teme] + 1;

            q.push(x1);
        }

        if (x2 > 0 and visited[x2] == false)
        {
            visited[x2] = true;

            cekori[x2] = cekori[teme] + 1;

            q.push(x2);
        }
    }

    cout << cekori[eX];

    return 0;
}
