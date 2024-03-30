#include <iostream>

using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    int rez = 0, m;
    for (int i = 0; i <= b - a; i++)
    {
        m = a + i;
        while (m > 0)
        {
            m /= 10;
            rez++;
        }
    }
    rez -= rez / k;
    cout << rez;
    return 0;
}