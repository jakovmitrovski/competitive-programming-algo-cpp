#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, maksimum = 0;

    cin >> n >> m;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        int broj, potrebno;

        cin >> broj;

        if (i < m % n)
            potrebno = m / n + 1;

        else
            potrebno = m / n;

        pair<int, int> par;

        par.first = broj;
        par.second = i;

        q.push(par);

        int brojac = 0;

        while (!q.empty())
        {
            if (brojac + q.front().first <= potrebno)
            {
                brojac += q.front().first;

                maksimum = max(maksimum, i - q.front().second);

                q.pop();
            }

            else
            {
                q.front().first -= potrebno - brojac;
                break;
            }

            if (brojac == potrebno)
                break;
        }
    }

    cout << maksimum;

    return 0;