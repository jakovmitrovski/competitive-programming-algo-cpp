#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, i, j, mat[102][102];

    cin >> n >> m;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> mat[i][j];
    vector<int> rez;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            int prov1 = 0, prov2 = 0, best = 999999999;

            int x = i, y = j;

            if (x > 0)
            {
                prov1 = 1;
                if (mat[x][y] < mat[x - 1][y])
                {
                    if (mat[x][y] < mat[x - 1][y])
                        prov2 = 1;
                    best = min(best, mat[x - 1][y] - mat[x][y]);
                }
            }

            if (prov1 == 1 && prov2 == 0)
                continue;

            prov1 = 0, prov2 = 0;

            if (x < n - 1)
            {
                prov1 = 1;
                if (mat[x][y] < mat[x + 1][y])
                {
                    if (mat[x][y] < mat[x + 1][y])
                        prov2 = 1;
                    best = min(best, mat[x + 1][y] - mat[x][y]);
                }
            }

            if (prov1 == 1 && prov2 == 0)
                continue;

            prov1 = 0, prov2 = 0;

            if (y > 0)
            {
                prov1 = 1;
                if (mat[x][y] < mat[x][y - 1])
                {
                    if (mat[x][y] < mat[x][y - 1])
                        prov2 = 1;
                    best = min(best, mat[x][y - 1] - mat[x][y]);
                }
            }

            if (prov1 == 1 && prov2 == 0)
                continue;

            prov1 = 0, prov2 = 0;

            if (y < m - 1)
            {
                prov1 = 1;
                if (mat[x][y] < mat[x][y + 1])
                {
                    if (mat[x][y] < mat[x][y + 1])
                        prov2 = 1;
                    best = min(best, mat[x][y + 1] - mat[x][y]);
                }
            }

            if (prov1 == 1 && prov2 == 0)
                continue;

            rez.push_back(best);
        }

    sort(rez.begin(), rez.end());

    for (int i = rez.size() - 1; i >= 0; i--)
        cout << rez[i] << " ";

    return 0;
}