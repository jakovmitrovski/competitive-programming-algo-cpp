#include <bits/stdc++.h>

using namespace std;

int main()
{
    int niza[10];

    for (int i = 0; i < 7; i++)
        cin >> niza[i];

    int mat[10][10];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++)
            cin >> mat[i][j];

    bool visited[100][100];

    memset(visited, false, sizeof(visited));

    int rez = 0;
    bool l = false;

    for (int p = 0; p < 7; p++)
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (niza[p] == mat[i][j] and visited[i][j] == false)
                {
                    visited[i][j] = true;
                    rez++;
                    l = true;
                    break;
                }
            }
            if (l == true)
            {
                l = false;
                break;
            }
        }

    if (rez != 7)
        cout << "NE";

    else
        cout << "DA";

    return 0;
}