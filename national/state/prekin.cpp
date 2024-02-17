#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, int>>> rebra;
vector<vector<int>> v(100000);
bool dali_ima;
bool visited[100000];
vector<pair<int, int>> upotrebeni;
int broj = 0;
bool visited1[100000];

void dfs(int teme, int kraj)
{
    visited[teme] = true;

    if (teme == kraj)
    {
        dali_ima = true;
        return;
    }

    for (int i = 0; i < v[teme].size(); i++)
        if (visited[v[teme][i]] == false)
            dfs(v[teme][i], kraj);

    return;
}
void dfs2(int teme)
{
    visited1[teme] = true;

    broj++;

    for (int i = 0; i < v[teme].size(); i++)
        if (visited1[v[teme][i]] == false)
            dfs2(v[teme][i]);

    return;
}

int main()
{
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        pair<int, pair<int, int>> par;

        par.first = c;
        par.second.first = a;
        par.second.second = b;

        rebra.push_back(par);
    }

    sort(rebra.begin(), rebra.end());

    int zbir = 0;

    for (int i = 0; i < rebra.size(); i++)
    {
        int a = rebra[i].second.first;
        int b = rebra[i].second.second;

        memset(visited, false, sizeof(visited));

        dfs(a, b);

        if (dali_ima == false)
        {
            v[a].push_back(b);
            v[b].push_back(a);

            pair<int, int> p;

            p.first = a;
            p.second = b;

            upotrebeni.push_back(p);

            zbir += rebra[i].first;
        }

        dali_ima = false;
    }

    dali_ima = false;

    cout << zbir << " ";

    for (int i = 0; i <= n + 3; i++)
        v[i].clear();

    memset(visited, false, sizeof(visited));

    int rezultat = 9999999;

    sort(rebra.begin(), rebra.end());

    for (int i = 0; i < upotrebeni.size(); i++)
    {
        zbir = 0;
        broj = 0;

        for (int j = 0; j < rebra.size(); j++)
        {
            int a = rebra[j].second.first;
            int b = rebra[j].second.second;

            memset(visited, false, sizeof(visited));

            if ((a == upotrebeni[i].first and b == upotrebeni[i].second) or (a == upotrebeni[i].second and b == upotrebeni[i].first))
                continue;

            else
            {
                dfs(a, b);

                if (dali_ima == false)
                {
                    v[a].push_back(b);
                    v[b].push_back(a);

                    zbir += rebra[j].first;
                }
            }

            dali_ima = false;
        }

        memset(visited1, false, sizeof(visited1));

        dfs2(1);

        if (broj == n)
            rezultat = min(rezultat, zbir);

        broj = 0;

        dali_ima = false;

        for (int k = 0; k <= n + 3; k++)
            v[k].clear();
    }

    cout << rezultat;

    return 0;
}