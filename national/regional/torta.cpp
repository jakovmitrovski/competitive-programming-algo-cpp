#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a;
    cin >> n >> a;
    int mat[a + 2][20];
    for (int i = 0; i < a; i++)
        for (int j = 0; j < 2; j++)
            cin >> mat[i][j];
    int zbir = 0, pom = 0, n1 = mat[0][0], n2 = mat[0][1];
    for (int i = 0; i < a; i++)
        if (mat[i][0] < n1)
            n1 = mat[i][0]; // najeftin paket
    for (int i = 0; i < a; i++)
        if (mat[i][1] < n2)
            n2 = mat[i][1]; // najeftino parce

    if (6 * n2 < n1)
    {
        zbir = n * n2;
        cout << zbir;
        return 0; // ako edno parce kosta 1
    }
    while (pom < n)
    {
        if (pom < n)
        {
            pom += 6;
            zbir += n1;
            if (pom == n)
            {
                cout << zbir;
                return 0;
            }
            if (pom > n)
            {
                if (pom - n > abs(pom - 6 - n))
                {
                    pom -= 6;
                    zbir -= n1;
                    zbir += min(n1, n2);
                    pom += 1;
                }
            }
        }
    }
    cout << zbir;
    return 0;
}