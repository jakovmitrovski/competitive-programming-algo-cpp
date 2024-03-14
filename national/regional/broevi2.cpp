#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b;
    if (a < b)
    {
        cout << "NE MOZE";
        return 0;
    }
    d = (a - b) / 2;
    c = b + d;
    if ((c + d != a and c - d != b) or (c + d != a and c - d == b) or (c + d == a and c - d != b))
    {
        cout << "NE MOZE";
        return 0;
    }
    if ((c < 0 and d < 0) or (c < 0 and d > 0) or (c > 0 and d < 0))
    {
        cout << "NE MOZE";
        return 0;
    }
    cout << c << " " << d;
    return 0;
}