#include <bits/stdc++.h>

using namespace std;

long double gcd(long double a, long double b)
{
    if (fabs(b) < 0.001)
        return a;

    return (gcd(b, a - floor(a / b) * b));
}
int main()
{
    long double a, b;
    cin >> a >> b;

    long double help = gcd(a, b);
    long long x = floor(a / help);
    long long y = floor(b / help);

    cout << "KUPI " << y << " DOBIJ " << x - y << " GRATIS";

    return 0;
}