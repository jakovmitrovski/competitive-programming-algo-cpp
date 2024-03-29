#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;

    cin >> n >> m >> k;

    bool visited[3][10002];

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < k; i++)
    {
        int a;

        cin >> a;

        int paren = a % 2;

        a /= 2;

        if (paren % 2 == 0)
            a--;

        for (int j = max(0, a - m); j <= min(6000, a + m); j++)
            visited[paren][j] = true;
    }

    int rez = 0;

    for (int i = 0; i < (n / 2); i++)
    {
        if (visited[0][i] == false)
        {
            rez++;

            for (int j = i; j <= min(6000, i + m); j++)
                visited[0][j] = true;
        }
    }

    for (int i = 0; i < (n / 2 + n % 2); i++)
    {
        if (visited[1][i] == false)
        {
            rez++;

            for (int j = i; j <= min(6000, i + m); j++)
                visited[1][j] = true;
        }
    }

    cout << rez;

    return 0;
}