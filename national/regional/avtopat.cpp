#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> v(100000);
int dalecina[100000];
bool visited[100000];

void dfs(int teme)
{
    visited[teme] = true;

    // cout << "teme e " << teme << endl;

    for (int i = 0; i < v[teme].size(); i++)
    {
        if (visited[v[teme][i].first] == false and teme < v[teme][i].first)
        {
            dalecina[v[teme][i].first] = v[teme][i].second + dalecina[teme];

            dfs(v[teme][i].first);
        }

        else if (visited[v[teme][i].first] == false and teme > v[teme][i].first)
        {
            dalecina[v[teme][i].first] = dalecina[teme] - v[teme][i].second;

            dfs(v[teme][i].first);
        }
    }

    return;
}

int main()
{

    int n, m, k1, k2;

    cin >> k1 >> k2 >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        pair<int, int> p;

        p.first = b;
        p.second = c;

        v[a].push_back(p);

        p.first = a;

        v[b].push_back(p);
    }

    memset(dalecina, -1, sizeof(dalecina));

    dalecina[k1] = 0;

    dfs(k1);

    if (visited[k2] == false)
    {
        cout << -1;
        return 0;
    }

    cout << abs(dalecina[k2]);

    return 0;
}