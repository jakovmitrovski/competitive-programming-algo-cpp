#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m;

    cin >> n >> m;

    vector<pair<long long, long long>> v;

    for (int i = 0; i < n; i++)
    {
        int a, b;

        cin >> a >> b;

        pair<long long, long long> p;

        p.first = a;
        p.second = b;

        v.push_back(p);
    }

    sort(v.begin(), v.end());

    long long rez = v[0].second;

    for (int i = 1; i < n; i++)
        if (v[i - 1].second < v[i].second)
            rez += v[i].second - v[i - 1].second;

    cout << rez;

    return 0;
}