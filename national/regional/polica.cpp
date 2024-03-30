#include <bits/stdc++.h>

using namespace std;

map<int, int> mapa;
vector<int> v;

int main()
{
    int n, k;

    cin >> n >> k;

    int niza[n + 2];

    for (int i = 0; i < n; i++)
    {
        cin >> niza[i];

        v.push_back(niza[i]);

        mapa[niza[i]] = i;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < k; i++)
    {
        int najmala = v[i];
        int najgolema = v[n - i - 1];

        swap(niza[mapa[najmala]], niza[mapa[najgolema]]);
    }

    for (int i = 0; i < n; i++)
        cout << niza[i] << " ";

    return 0;
}