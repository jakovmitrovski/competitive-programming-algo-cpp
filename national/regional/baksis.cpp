#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x, y;

    cin >> x >> y;

    int mincena, makscena;

    mincena = ceil(20.0 * x / 19.0);
    makscena = floor(10.0 * x / 9.0);

    if (makscena > y)
        makscena = y;

    if (mincena % 5 != 0)
        mincena += 5 - (mincena % 5);

    if (makscena % 5 != 0)
        makscena -= (makscena % 5);

    if (mincena > makscena)
        cout << 0;

    else
        cout << (makscena - mincena) / 5 + 1;

    return 0;
}