#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int rez = 0;

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;

        cin >> a;

        v.push_back(a);
    }

    while (true)
    {
        int najgolem = -1, pozicija = 0;

        for (int i = 1; i < n; i++)
            if (najgolem < v[i])
            {
                najgolem = v[i];
                pozicija = i;
            }

        if (v[0] > najgolem)
        {
            cout << rez;

            return 0;
        }

        v[pozicija]--;

        v[0]++;

        rez++;
    }

    return 0;
}