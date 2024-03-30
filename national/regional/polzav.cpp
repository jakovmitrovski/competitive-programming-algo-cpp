#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    int zbir = 0, br = 0;

    while (zbir < a)
    {
        br++;
        zbir += b;

        if (zbir >= a)
            break;

        zbir -= c;
    }

    cout << br;

    return 0;
}