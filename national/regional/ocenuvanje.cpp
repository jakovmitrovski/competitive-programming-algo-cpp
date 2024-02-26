#include <bits/stdc++.h>

using namespace std;

vector<long long> v;

int n;

long long presmetaj(int k)
{
    long long ret = 0;

    for (int i = 0; i <= k; i++)
        ret += min(v[i], v[k]);

    for (int i = k + 1; i < n; i++)
        ret += min(v[i], v[k] - 1);

    return ret;
}

int main()
{

    long long k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        long long a;

        cin >> a;

        v.push_back(a);
    }

    long long rez[n + 1], kraj = 0, zbir = 0;

    for (int i = 0; i < n; i++)
        zbir += v[i];

    if (zbir < k)
    {
        cout << kraj << endl;

        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        rez[i] = presmetaj(i);

        if (rez[i] > k)
            kraj++;
    }

    cout << kraj;

    return 0;
}