#include <bits/stdc++.h>

using namespace std;

int id[300001];
int parent[300001][20];
int top_flavor[300001];
int depth[300001];

int find_lca(int a, int b)
{
    if (depth[a] != depth[b])
    {

        if (depth[a] > depth[b])
            swap(a, b);

        int k = depth[b] - depth[a];

        for (int i = 0; i < 20; i++)
            if (k & (1 << i))
                b = parent[b][i];
    }

    if (a == b)
        return a;

    for (int i = 19; i >= 0; i--)
    {
        if (parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
        id[i] = i;

    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'a')
        {
            int a;
            cin >> a;

            while (a != id[a])
                a = id[a];

            parent[i][0] = a;
            depth[i] = depth[a] + 1;
            top_flavor[i] = i;

            for (int j = 1; j < 20; j++)
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
        else if (c == 'b')
        {
            int a;
            cin >> a;

            while (a != id[a])
                a = id[a];

            id[i] = id[parent[a][0]];
            top_flavor[i] = id[parent[a][0]];
            depth[i] = depth[a] - 1;

            cout << top_flavor[a] << endl;
        }
        else
        {

            int a, b;
            cin >> a >> b;

            while (a != id[a])
                a = id[a];
            while (b != id[b])
                b = id[b];

            id[i] = a;
            depth[i] = depth[a];
            top_flavor[i] = top_flavor[a];

            int x = find_lca(a, b);
            cout << depth[x] << endl;
        }
    }
    return 0;
}