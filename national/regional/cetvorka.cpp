#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int niza[n + 2];

    for (int i = 0; i < n; i++)
        cin >> niza[i];

    int rez = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                for (int p = k + 1; p < n; p++)
                    if (niza[i] * niza[k] == niza[j] * niza[p])
                        rez++;

    cout << rez;

    return 0;
}