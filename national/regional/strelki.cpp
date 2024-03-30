#include <bits/stdc++.h>

using namespace std;

int parent[300003];
int dlabocina[300003];

int find(int x)
{
    int y = x;

    while (x != -1 and x != parent[x])
        x = parent[x];

    parent[y] = x;

    return x;
}

void unite(int a, int b, bool ciklus)
{

    int x = find(a), y = find(b);

    if (ciklus)
    {
        parent[x] = -1;
        parent[y] = -1;
    }
    else
    {
        if (dlabocina[x] > dlabocina[y])
            parent[y] = x;

        else if (dlabocina[x] < dlabocina[y])
            parent[x] = y;

        else
        {
            parent[x] = y;
            dlabocina[x]++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, bool>> niza;
    niza.push_back({0, false});
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        dlabocina[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        niza.push_back({a, false});
    }
    int q;
    cin >> q;
    vector<pair<int, int>> v;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        if (a == 2)
            niza[b].second = true;
    }
    reverse(v.begin(), v.end());
    vector<int> rez;

    for (int i = 1; i <= n; i++)
    {
        if (!niza[i].second and niza[i].first != 0)
        {
            int x = find(i), y = find(niza[i].first);
            if (x != y)
            {
                if (y == -1)
                    parent[x] = -1;
                else
                    unite(i, niza[i].first, false);
            }
            else
                unite(i, niza[i].first, true);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        int a = v[i].first, b = v[i].second;

        if (a == 1)
        {
            int x = find(b);
            rez.push_back(x);
        }
        else
        {
            int x = find(b), y = find(niza[b].first);
            if (x != y)
            {
                if (y == -1)
                    parent[x] = -1;
                else
                    unite(x, y, false);
            }
            else
                unite(x, y, true);
        }
    }

    reverse(rez.begin(), rez.end());

    for (int i = 0; i < rez.size(); i++)
        if (rez[i] == -1)
            cout << "CIKLUS" << endl;
        else
            cout << rez[i] << endl;

    return 0;
}