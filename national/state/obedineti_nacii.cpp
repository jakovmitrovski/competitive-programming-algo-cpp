#include <bits/stdc++.h>

using namespace std;

int n, m;
bool visited[1000002];
vector<vector<int>> v(1000002);
int br = 0;

void dfs(int teme)
{
    // cout << "vleguva tuka za temeto "<<teme<<endl;
    br++;

    visited[teme] = true;

    for (int i = 0; i < v[teme].size(); i++)
        if (visited[v[teme][i]] == false)
            dfs(v[teme][i]);

    return;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    long long rez = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            dfs(i);

            rez += (long long)br * (n - br);

            br = 0;
        }
    }

    cout << rez / 2;

    return 0;
}