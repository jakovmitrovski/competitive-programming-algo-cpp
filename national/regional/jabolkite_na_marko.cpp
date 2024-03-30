#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    if (n % 4 == 0)
        cout << 0;
    else if (n % 4 == 1)
        cout << 27;
    else if (n % 4 == 2)
        cout << 18;

    else
        cout << 9;

    return 0;
}