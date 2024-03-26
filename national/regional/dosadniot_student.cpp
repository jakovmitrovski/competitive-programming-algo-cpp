#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int c = 0, g = 0;
    for (int i = 1; i <= a; i++)
    {
        g += i;
        c++;
        if (g == a)
            break;
    }
    cout << c;
    return 0;
}