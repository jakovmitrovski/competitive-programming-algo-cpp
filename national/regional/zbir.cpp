#include <iostream>

using namespace std;

long long n;

long long koj_pocetok(long long c)
{
    if (c == 1)
        return c;

    return 10 * koj_pocetok(c - 1);
}

void binary(long long a, long long b)
{
    // cout << "vleguva tuka za " << a << " i " << b << endl;

    long long mid = (a + b) / 2;

    long long c = mid;

    long long broj = 0;

    while (c > 0)
    {
        broj += c;
        c /= 10;
    }

    if (broj == n)
    {
        cout << mid;
        return;
    }

    if (broj > n)
    {
        binary(a, mid);
    }

    else
    {
        binary(mid + 1, b);
    }

    return;
}

int main()
{
    long long c;

    cin >> n >> c;

    binary(koj_pocetok(c), koj_pocetok(c + 1) - 1);

    return 0;
}