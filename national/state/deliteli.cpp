#include <bits/stdc++.h>

using namespace std;

int stepen(int broj, int stp)
{
    if (stp == 0)
        return 1;

    return broj * stepen(10, stp - 1);
}

bool poln_kvadrat(int broj)
{
    int a = sqrt(broj);

    if (a * a == broj)
        return true;

    return false;
}

int deliteli(int koren_broj, int broj)
{
    int delitel = 0;

    // cout << "vlaga za broj " << broj << " i koren_broj " << koren_broj << endl;

    if (poln_kvadrat(broj) == true)
    {
        for (int i = 1; i < koren_broj; i++)
            if (broj % i == 0)
                delitel += 2;

        delitel++;
    }

    else
    {
        // cout << "vlaga tuka " << endl;

        for (int i = 1; i <= koren_broj; i++)
            if (broj % i == 0)
            {
                delitel += 2;
                // cout << " delitel mu e " << i << endl;
            }
    }

    return delitel;
}

int main()
{
    int n;

    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int a;

        cin >> a;

        v.push_back(a);
    }

    sort(v.begin(), v.end());

    vector<pair<int, int>> rez;

    do
    {
        int k = n - 1, broj = 0;

        for (int i = 0; i < n; i++)
        {
            broj += v[i] * stepen(10, k);
            k--;
        }

        int kolku = deliteli(sqrt(broj), broj);

        pair<int, int> p;

        p.first = broj;
        p.second = kolku;

        // cout << broj << " ima " << kolku << " deliteli " << endl;

        rez.push_back(p);

    } while (next_permutation(v.begin(), v.end()));

    sort(rez.begin(), rez.end());

    vector<pair<int, int>> rez1;

    pair<int, int> p1;

    p1.first = rez[0].second;
    p1.second = rez[0].first;

    rez1.push_back(p1);

    for (int i = 1; i < rez.size(); i++)
        if (rez[i - 1].first != rez[i].first)
        {
            pair<int, int> p2;

            p2.first = rez[i].second;
            p2.second = rez[i].first;

            rez1.push_back(p2);
        }

    sort(rez1.begin(), rez1.end());

    int p = rez1[0].first;

    cout << p << endl;

    cout << rez1[0].second << " ";

    for (int i = 1; i < rez1.size(); i++)
        if (rez1[i].first == p)
            cout << rez1[i].second << " ";

    return 0;
}