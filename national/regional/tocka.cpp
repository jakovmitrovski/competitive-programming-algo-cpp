#include <iostream>
using namespace std;

int main()
{
    int px, py;
    cin >> px >> py;

    int a, b;
    cin >> a >> b;

    int x, y;
    cin >> x >> y;

    if ((x >= px && x <= px + a) && (y >= py && y <= py + b))
    {
        if (x == px || x == px + a || y == py || y == py + b)
            cout << "strana" << endl;
        else
            cout << "vnatre" << endl;
    }
    else
    {
        cout << "nadvor" << endl;
    }

    return 0;
}