#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int d[10] = {0};

    while (n > 0)
    {
        int a = (n % 10);

        if (a == 9)
            a = 6;

        d[a]++;

        n /= 10;
    }

    if (d[6] % 2 == 0)
        d[6] /= 2;
    else
        d[6] = (d[6] / 2) + 1;

    int rez = 0;
    for (int i = 0; i <= 8; i++)
        if (d[i] > rez)
            rez = d[i];

    cout << rez << endl;
    return 0;
}