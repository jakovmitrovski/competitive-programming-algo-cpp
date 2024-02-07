#include <bits/stdc++.h>

using namespace std;

vector<long double> v;

int main()
{
    int n, popust;

    cin >> n >> popust;

    for (int i = 0; i < n; i++)
    {
        long double a;

        cin >> a;

        v.push_back(a);
    }

    sort(v.begin(), v.end());

    reverse(v.begin(), v.end());

    int kolku = n / 3;

    for (int i = 0; i < kolku; i++)
    {
        long double pomos = v[i] * popust / 100;

        v[i] -= pomos;
    }

    long double zbir = 0.00;

    for (int i = 0; i < n; i++)
        zbir += v[i];

    cout << fixed;

    cout << setprecision(2) << zbir;

    return 0;
}
