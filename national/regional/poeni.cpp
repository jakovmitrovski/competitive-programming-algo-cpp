#include <iostream>

using namespace std;

int main()
{
    int p, d, n;
    cin >> p >> d >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    int zbir = p, inkrement = d;
    for (int i = 2; i < n; i++)
    {
        zbir += (p + inkrement);
        inkrement += d;
    }
    cout << zbir;
    return 0;
}