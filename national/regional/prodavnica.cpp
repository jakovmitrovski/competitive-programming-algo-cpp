#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0;
        return 0;
    }
    int br = 0, c;
    c = b - a;
    while (c - 5 >= 0)
    {
        br++;
        c -= 5;
    }
    while (c - 2 >= 0)
    {
        br++;
        c -= 2;
    }
    while (c - 1 >= 0)
    {
        br++;
        c -= 1;
    }
    cout << br;
    return 0;
}