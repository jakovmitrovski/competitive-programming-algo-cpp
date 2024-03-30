#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if ((a + b) % 2 == 1)
        cout << (((a + b) - 1) / 2) * 7;
    else
        cout << ((a + b) / 2) * 7;
    return 0;
}