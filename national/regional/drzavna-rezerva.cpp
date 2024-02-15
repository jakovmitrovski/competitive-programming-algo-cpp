#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> par;
        par.first = a;
        par.second = b;

        v.push_back(par);
    }
    sort(v.begin(), v.end());
    int zbir = 0, rez = 0, c;

    for (int i = 0; i < n; i++)
    {
        zbir += v[i].second;
        rez += (v[i].first * v[i].second);
        if (zbir == k)
            break;
        else if (zbir > k)
        {
            zbir -= v[i].second;
            rez -= (v[i].first * v[i].second);
            c = k - zbir;
            v[i].second = c;
            rez += (v[i].first * v[i].second);
            zbir += v[i].second;
            break;
        }
    }
    cout << rez;

    return 0;
}