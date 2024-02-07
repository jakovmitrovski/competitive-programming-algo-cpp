#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
vector<int> vektor;
int n, m;

bool zadovoleni_uslovi()
{
    for (int i = 0; i < m; i++)
    {
        int a = v[i].first, b = v[i].second, pozicija1, pozicija2;

        for (int j = 0; j < n; j++)
        {
            if (vektor[j] == a)
                pozicija1 = j;

            if (vektor[j] == b)
                pozicija2 = j;
        }

        if (pozicija1 > pozicija2)
            return false;
    }

    return true;
}

int main()
{
    cin >> n;

    int niza[n + 2];

    for (int i = 0; i < n; i++)
    {
        cin >> niza[i];
        vektor.push_back(i + 1);
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        pair<int, int> p;

        int a, b;

        cin >> a >> b;

        p.first = b;
        p.second = a;

        v.push_back(p);
    }

    vector<int> rez;
    int napor = 9999999;

    do
    {
        if (zadovoleni_uslovi() == true)
        {
            int p = 0;
            for (int i = 1; i < n; i++)
                p = p + i * niza[vektor[i] - 1];

            if (p < napor)
            {
                napor = p;
                rez = vektor;
            }
        }

    } while (next_permutation(vektor.begin(), vektor.end()));

    for (int i = 0; i < n; i++)
        cout << rez[i] << " ";

    return 0;
}