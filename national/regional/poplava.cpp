#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int pi, xi;
        cin >> pi >> xi;
        v.push_back(make_pair(xi, pi));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int prod = 1000000000, lugje = 0;
    int vk = 0;
    for (int i = 0; i < (int)v.size(); i++)
    {
        int prod2 = v[i].first;
        vk = vk + v[i].second;
        if (prod2 * vk >= prod * lugje)
        {
            prod = prod2;
            lugje = vk;
        }
    }
    cout << (prod * lugje) << endl;
    return 0;
}