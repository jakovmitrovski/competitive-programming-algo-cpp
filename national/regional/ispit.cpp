#include <iostream>

using namespace std;

int main()
{
    int a, b, rez;

    cin >> a >> b;

    if (a == b)
    {
        cout << 2 * a - 2 << endl;

        return 0;
    }

    else
    {
        if (a < b)
            rez = 2 * a - 1;

        else
            rez = 2 * b - 2;
    }

    cout << rez << endl;

    return 0;
}