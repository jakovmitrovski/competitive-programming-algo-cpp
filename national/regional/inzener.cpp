#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long m, k, pred;

    cin >> m >> k >> pred;

    long long rez = pred;

    for (long long i = 1; i <= 1000000; i++)
    {
        rez += 30 * k - 40 * m;

        if (rez <= 0)
        {
            cout << "DA";
            return 0;
        }
    }

    cout << "NE";

    return 0;
}