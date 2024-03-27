#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    int p = a, k = b;

    int niza[5][2];

    memset(niza, 0, sizeof(niza));

    int i = 0;

    while (p > 0 and k > 0)
    {
        int c = p % 10;

        int d = k % 10;

        int e = p % 10;

        int f = k % 10;

        if (c != d)
        {
            while (c != d)
            {
                c++;
                niza[i][0]++;

                if (c == 10)
                    c = 0;
            }
        }

        if (e != f)
        {
            while (e != f)
            {
                e--;
                niza[i][1]++;

                if (e == -1)
                    e = 9;
            }
        }

        i++;

        p /= 10;

        k /= 10;
    }

    int rez = 0;

    for (int i = 0; i < 4; i++)
        rez += min(niza[i][0], niza[i][1]);

    cout << rez;

    return 0;
}