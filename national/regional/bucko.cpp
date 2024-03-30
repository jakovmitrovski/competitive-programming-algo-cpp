#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int niza[n + 2];
    vector<long long> dp;
    map<long long, long long> mapa;
    dp.push_back(0);
    mapa[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> niza[i];
        dp.push_back(dp[i - 1] + niza[i]);
        mapa[dp[i]] = 0;
    }

    long long rez = 0;

    sort(dp.begin(), dp.end());

    for (int i = 0; i <= n; i++)
        mapa[dp[i]]++;

    for (pair<long long, long long> p : mapa)
        if (p.second >= 2)
            rez += (p.second * (p.second - 1)) / 2;
    cout << rez << endl;
    return 0;
}