#include <iostream>

using namespace std;

int main()
{
    long long broj, k;

    cin >> broj >> k;

    long long x = 1;

    for (long long i = broj + 1; i > 0; i += x)
    {
        int sedmici = 0;

        long long p = i;

        while (p > 0)
        {
            if (p % 10 == 7)
                sedmici++;

            p /= 10;
        }

        if (sedmici >= k)
        {
            cout << i;
            return 0;
        }

        if ((i / x) % 10 == 7)
            x *= 10;
    }

    return 0;
}