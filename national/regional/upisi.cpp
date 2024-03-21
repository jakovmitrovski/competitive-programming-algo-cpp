#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
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
    int rez = 0;
    bool projdeno[30000] = {0};
    for (int i = 0; i < n; i++)
    {
        int br = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (v[i].first == v[j].first and v[i].second == v[j].second and projdeno[j] == 0)
            {
                br++;
                projdeno[j] = 1;
            }
            if (br > rez)
                rez = br;
        }
    }
    cout << rez;

    return 0;
}
