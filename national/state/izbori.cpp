#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<pair<int, int>, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pair<pair<int, int>, int> tu;
        tu.first.first = a;
        tu.first.second = b;
        tu.second = i + 1;

        v.push_back(tu);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int naj = v[0].first.second;
    int rez = v[0].second;
    for (int i = 0; i < k; i++)
    {
        if (v[i].first.second > naj)
        {
            naj = v[i].first.second;
            rez = v[i].second;
        }
    }
    cout << rez;

    return 0;
}