#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a == 1)
        cout << 31;
    else if (a == 2 and b == 2000)
        cout << 29;
    else if (a == 2)
    {
        if ((b % 4 == 0 and b % 100 != 0) or b % 400 == 0)
            cout << 29;
        else
            cout << 28;
    }

    else if (a == 3)
        cout << 31;
    else if (a == 4)
        cout << 30;
    else if (a == 5)
        cout << 31;
    else if (a == 6)
        cout << 30;
    else if (a == 7)
        cout << 31;
    else if (a == 8)
        cout << 31;
    else if (a == 9)
        cout << 30;
    else if (a == 10)
        cout << 31;
    else if (a == 11)
        cout << 30;
    else
        cout << 31;
    return 0;
}