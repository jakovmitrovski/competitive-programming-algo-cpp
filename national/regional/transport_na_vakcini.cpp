#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> v(10000);
    vector<vector<pair<int, int>>> so_sneg(10000);

    for (int i = 0; i < m; i++)
    {
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        x--;
        y--;
        if (t == 1)
        {
            so_sneg[x].push_back({y, z});
            so_sneg[y].push_back({x, z});
        }
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }

    bool visited1[n + 2], visited2[n + 2];

    int cekori_normal[n + 2], cekori_sneg[n + 2];
    for (int i = 0; i < n + 2; i++)
    {
        cekori_normal[i] = 1 << 20;
        cekori_sneg[i] = 1 << 20;
        visited1[i] = false;
        visited2[i] = false;
    }

    cekori_normal[0] = 0;

    while (true)
    {
        int teme = -1, najmal = 1 << 20;

        for (int i = 0; i < n; i++)
            if (cekori_normal[i] < najmal && !visited1[i])
            {
                teme = i;
                najmal = cekori_normal[i];
            }
        if (teme == -1)
            break;

        visited1[teme] = true;

        for (int i = 0; i < v[teme].size(); i++)
            if (cekori_normal[v[teme][i].first] > cekori_normal[teme] + v[teme][i].second)
            {
                cekori_normal[v[teme][i].first] = cekori_normal[teme] + v[teme][i].second;
            }
    }

    cekori_sneg[0] = 0;

    while (true)
    {
        int teme = -1, najmal = 1 << 20;

        for (int i = 0; i < n; i++)
            if (cekori_sneg[i] < najmal && !visited2[i])
            {
                teme = i;
                najmal = cekori_sneg[i];
            }
        if (teme == -1)
            break;

        visited2[teme] = true;

        for (int i = 0; i < so_sneg[teme].size(); i++)
            if (cekori_sneg[so_sneg[teme][i].first] > cekori_sneg[teme] + so_sneg[teme][i].second)
            {
                cekori_sneg[so_sneg[teme][i].first] = cekori_sneg[teme] + so_sneg[teme][i].second;
            }
    }

    cout << cekori_normal[n - 1] << endl;

    if (cekori_normal[n - 1] == cekori_sneg[n - 1])
        cout << "DA";
    else
        cout << "NE";

    return 0;
}