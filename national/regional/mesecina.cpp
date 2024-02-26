#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v1;
vector<vector<pair<int, double>>> v(100000);

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;

        cin >> a >> b;

        pair<int, int> par4;

        par4.first = a;
        par4.second = b;

        v1.push_back(par4);
    }

    for (int i = 0; i < v1.size(); i++)
        for (int j = 0; j < v1.size(); j++)
        {

            int a = v1[i].first;
            int b = v1[j].first;
            int c = v1[i].second;
            int d = v1[j].second;

            if (i != j and sqrt((a - b) * (a - b) + (c - d) * (c - d)) - 10 < 0.00001)
            {
                pair<int, double> p4;

                // cout << (double)sqrt((a-b)*(a-b) + (c-d)*(c-d)) << endl;

                p4.first = i;
                p4.second = (double)sqrt((a - b) * (a - b) + (c - d) * (c - d));

                v[j].push_back(p4);

                p4.first = j;

                v[i].push_back(p4);
            }
        }

    bool visited[n + 2];
    double cekori[n + 2];

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++)
        cekori[i] = 9999999.0;

    cekori[0] = 0.0;

    while (true)
    {
        int teme = -1;

        double najmal = 9999999;

        for (int i = 0; i < n; i++)
            if (visited[i] == false and cekori[i] < najmal)
            {
                najmal = cekori[i];
                teme = i;
            }

        if (teme == -1)
            break;

        visited[teme] = true;

        for (int i = 0; i < v[teme].size(); i++)
            cekori[v[teme][i].first] = min(cekori[v[teme][i].first], cekori[teme] + v[teme][i].second);
    }

    cout << fixed;

    cout << setprecision(7) << (double)cekori[n - 1];

    return 0;
}