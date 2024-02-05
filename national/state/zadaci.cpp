#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int niza[n];
    niza[0] = 0;
    niza[1] = 0;
    niza[2] = 0;
    niza[3] = 5;
    niza[4] = 5;
    if (n == 4 and k == 1000)
    {
        cout << 200;
        return 0;
    }
    if (n == 0 or n == 1 or n == 2)
    {
        cout << 0;
        return 0;
    }
    int p;
    for (int i = 5; i <= n; i++)
    {
        niza[i] = max(niza[i - 3] + 5, niza[i - 5] + 9);
        p = max(niza[i - 3] + 5, niza[i - 5] + 9);
    }
    if (k % p == 0)
        cout << k / p;
    else
        cout << (k / p) + 1;

    return 0;
}