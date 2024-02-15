#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int c, d;
    int rez = 0, m = 0;
    while (a > 0 or b > 0)
    {
        c = a % 10;
        d = b % 10;
        if (c + d + m > 9)
        {
            m = 1;
            rez++;
        }
        else
            m = 0;
        a /= 10;
        b /= 10;
    }
    cout << rez;
    return 0;
}