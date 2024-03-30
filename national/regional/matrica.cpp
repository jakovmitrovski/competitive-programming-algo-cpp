#include <iostream>

using namespace std;

int main()
{
    int n, m, i, k;
    cin >> n >> m >> i >> k;
    if (i >= 1 and i <= n and k >= 1 and k <= m)
        cout << "DA";
    else
        cout << "NE";
    return 0;
}