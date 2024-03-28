#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 3 == 1)
        cout << 2;
    else if ((a + b + c) % 3 == 2)
        cout << 1;
    else
        cout << 0;
    return 0;
}