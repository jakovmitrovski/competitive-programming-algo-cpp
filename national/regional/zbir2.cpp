#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    cout << max((a * a) + b + c, max(a + (b * b) + c, a + b + (c * c)));

    return 0;
}