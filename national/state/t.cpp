#include <iostream>

using namespace std;

int main()
{
    int n, k;

    cin >> n >> k;

    int niza[n + 2];

    for (int i = 0; i < n; i++)
        cin >> niza[i];

    int zbir = 0, i = 0, j = 1;

    zbir = niza[0];

    int br = 0, rez = 0;

    while (i != n and j != n)
    {

        if (i == j)
            zbir = 0;

        if (zbir + niza[j] <= k)
        {
            zbir += niza[j];
            j++;
            br++;
        }

        else
        {
            zbir -= niza[i];
            i++;
        }

        if (rez <= j - i)
            rez = j - i;
    }

    while (j <= n)
        if (zbir + niza[n - 1] <= k)
        {
            j++;

            zbir += niza[n - 1];
        }

        else
        {
            zbir -= niza[n - i];

            i++;
        }

    cout << rez << endl;

    return 0;
}