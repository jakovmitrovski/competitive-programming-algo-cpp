#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int mat[1000][10000] = {0};
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1;
    }
    int rez = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (mat[i][j] == 1)
                if (mat[j][i] == 0)
                    rez++;
    cout << rez;
    return 0;
}