#include <bits/stdc++.h>

using namespace std;

vector<string> zborovi;

long long stepen(long long a, long long b)
{
    long long r = 1;

    for (int i = 1; i <= b; i++)
        if (r > 100000000000)
            return r;
        else
            r = r * a;

    return r;
}

int main()
{
    long long n, m, k, x;

    cin >> n >> m >> k >> x;

    string s;

    cin >> s;

    for (int i = 0; i < m; i++)
    {
        string t;

        cin >> t;

        sort(t.begin(), t.end());

        zborovi.push_back(t);
    }

    long long pominati = 0;

    string rezultat = "";

    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            if (pominati + (j + 1) * stepen(k, m - i - 1) >= x)
            {
                rezultat += zborovi[i][j];

                pominati += j * stepen(k, m - i - 1);

                break;
            }

    int r = 0;

    for (int i = 0; i < s.size(); i++)
        if (s[i] == '#')
        {
            cout << rezultat[r];
            r++;
        }
        else
            cout << s[i];

    return 0;
}