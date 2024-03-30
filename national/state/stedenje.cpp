#include <iostream>

using namespace std;

int main()
{
    int n, a, b;

    cin >> n >> a >> b;

    if (a >= b)
    {
        cout << "NE";
        return 0;
    }

    int rez = 0, zbir = 0;

    while (1)
    {
        if (n == zbir)
        {
            cout << rez;
            return 0;
        }

        if (zbir > n)
        {
            cout << "NE";
            return 0;
        }

        n += a;
        zbir += b;
        rez++;
    }

    return 0;
}