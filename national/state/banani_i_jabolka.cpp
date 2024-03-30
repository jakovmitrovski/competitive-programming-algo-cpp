#include <bits/stdc++.h>

using namespace std;

bool poln_kvadrat(int broj)
{
    int c = sqrt(broj);

    if (c * c == broj)
        return true;

    return false;
}

vector<int> najdi_deliteli(int broj)
{
    vector<int> v2;

    int c = sqrt(broj);

    if (poln_kvadrat(broj) == true)
    {
        for (int i = 1; i < c; i++)
            if (broj % i == 0)
            {
                v2.push_back(i);
                v2.push_back(broj / i);
            }

        v2.push_back(c);
    }

    else
    {
        for (int i = 1; i <= c; i++)
            if (broj % i == 0)
            {
                v2.push_back(i);
                v2.push_back(broj / i);
            }
    }

    sort(v2.begin(), v2.end());

    return v2;
}

int main()
{
    int a, b;

    cin >> a >> b;

    vector<int> v, v1;

    v = najdi_deliteli(a);
    v1 = najdi_deliteli(b);

    int rez = 0;

    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v1.size(); j++)
            if (v[i] == v1[j])
            {
                rez++;
                break;
            }

    cout << rez;

    return 0;
}