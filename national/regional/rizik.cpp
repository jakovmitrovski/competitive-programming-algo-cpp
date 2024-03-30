#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v(100002);

int main()
{

    int n, br_osvoeni_kosta, br_osvoeni_kiril, paricki;

    cin >> n >> br_osvoeni_kosta >> br_osvoeni_kiril >> paricki;

    bool visited_kosta[n + 2];

    memset(visited_kosta, false, sizeof(visited_kosta));

    bool visited_kiril[n + 2];

    memset(visited_kiril, false, sizeof(visited_kiril));

    int kosta[br_osvoeni_kosta + 2];

    for (int i = 1; i <= br_osvoeni_kosta; i++)
    {
        cin >> kosta[i];

        visited_kosta[kosta[i]] = true;
    }

    int kiril[br_osvoeni_kiril + 2];

    for (int i = 1; i <= br_osvoeni_kiril; i++)
    {
        cin >> kiril[i];

        visited_kiril[kiril[i]] = true;
    }

    int m;

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int rez = 0;

    for (int i = 1; i <= n; i++)
        if (visited_kosta[i] == true and visited_kiril[i] == false and paricki > 0)
        {
            queue<int> q;

            q.push(i);

            // cout << "vlaga za i " << i << endl;

            while (!q.empty())
            {
                int teme = q.front();

                q.pop();

                // cout << " vlaga za teme " << teme << endl;

                for (int j = 0; j < v[teme].size(); j++)
                    if (visited_kosta[v[teme][j]] == false and visited_kiril[v[teme][j]] == false and paricki > 0)
                    {
                        visited_kosta[v[teme][j]] = true;

                        q.push(v[teme][j]);

                        // cout << "gradot " << v[teme][j] << " stanuva true " << endl;

                        paricki--;

                        rez++;
                    }
            }
        }

    cout << rez;

    return 0;
}