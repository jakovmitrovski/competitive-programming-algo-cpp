#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int mat[301][301];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = 0; k < n; k++)
                if (k != i and k != j and mat[i][k] + mat[k][j] < mat[i][j])
                {
                    cout << "GRESHKA" << endl;
                    return 0;
                }

    long long rez = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            bool l = true;

            for (int k = 0; k < n and l; k++)
                if (k != i and k != j and mat[i][k] + mat[k][j] == mat[i][j])
                    l = false;

            if (l)
                rez += mat[i][j];
        }

    cout << rez << endl;

    return 0;
}