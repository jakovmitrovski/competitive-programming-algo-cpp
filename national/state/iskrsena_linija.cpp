#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;

    for (int i = 0; i < 4; i++)
    {
        int a;

        cin >> a;

        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int rez = 0;

    do
    {
        int dolzina = min(v[0], v[1]);
        int sirina = min(v[2], v[3]);

        rez = max(dolzina * sirina, rez);

    } while (next_permutation(v.begin(), v.end()));

    cout << rez;

    return 0;
}