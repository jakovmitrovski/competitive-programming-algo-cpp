#include <bits/stdc++.h>

using namespace std;

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

    long long zbir = 0;

    for (int i = 0; i < v.size() - 1; i++)
        zbir += v[i];

    if (zbir > v[v.size() - 1])
        cout << zbir + v[v.size() - 1] << endl;

    else
        cout << zbir + v[v.size() - 1] + (v[v.size() - 1] - zbir) << endl;

    return 0;
}