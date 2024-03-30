#include <bits/stdc++.h>

using namespace std;

int mat2[100][100];
bool visited[10000];
bool l;
int kolku_kecovi = 0;

vector<vector<int>> v_horizontalno(100002), v_vertikalno(100002);

bool proveri()
{
    for (int i = 0; i < kolku_kecovi; i++)
        if (visited[i] == false)
            return false;

    return true;
}

void dfs(int teme, int cekor)
{
    visited[teme] = true;

    if (proveri() == true)
    {
        l = true;
        return;
    }

    if (cekor % 2 == 1)
    {
        for (int i = 0; i < v_horizontalno[teme].size(); i++)
            if (visited[v_horizontalno[teme][i]] == false)
            {
                dfs(v_horizontalno[teme][i], cekor + 1);

                if (l == true)
                    return;
            }
    }

    else
    {
        for (int i = 0; i < v_vertikalno[teme].size(); i++)
            if (visited[v_vertikalno[teme][i]] == false)
            {
                dfs(v_vertikalno[teme][i], cekor + 1);
                if (l == true)
                    return;
            }
    }

    visited[teme] = false;

    return;
}

int mat[10][10];

int main()
{
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 1)
            {
                mat2[i][j] = kolku_kecovi;
                kolku_kecovi++;
            }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 1)
            {
                for (int k = 0; k < n; k++)
                    if (k != i and mat[k][j] == 1)
                        v_vertikalno[mat2[i][j]].push_back(mat2[k][j]);

                for (int k = 0; k < m; k++)
                    if (k != j and mat[i][k] == 1)
                        v_horizontalno[mat2[i][j]].push_back(mat2[i][k]);
            }

    for (int i = 0; i < kolku_kecovi; i++)
    {
        memset(visited, 0, sizeof(visited));

        dfs(i, 1);

        if (l == true)
        {
            cout << "DA" << endl;
            return 0;
        }
    }

    cout << "NE" << endl;

    return 0;
}