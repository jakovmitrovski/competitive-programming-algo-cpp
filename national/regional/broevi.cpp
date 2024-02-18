#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int c1, c2, c3, c4, br = 0;
    for (int i = a; i <= b; i++)
    {
        c1 = i % 10;
        c2 = (i / 10) % 10;
        c3 = (i / 100) % 10;
        c4 = (i / 1000) % 10;
        if (c1 > c2 and c1 > c3 and c1 > c4 and c2 > c3 and c2 > c4 and c3 > c4)
            br++;
    }
    cout << br;
    return 0;
}