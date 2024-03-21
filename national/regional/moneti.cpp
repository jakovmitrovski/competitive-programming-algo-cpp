#include <iostream>
using namespace std;
int main()
{
    int a[4];
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    if ((a[0] == 5 and a[1] == 5 and a[2] == 5 and a[3] == 5) or (a[0] == 0 and a[1] == 0 and a[2] == 0 and a[3] == 0))
        cout << 0;
    else if ((a[0] == 5 and a[1] == 5 and a[2] == 5 and a[3] == 0) or (a[0] == 5 and a[1] == 5 and a[2] == 0 and a[3] == 5) or (a[0] == 5 and a[1] == 0 and a[2] == 5 and a[3] == 5) or (a[0] == 0 and a[1] == 5 and a[2] == 5 and a[3] == 5))
        cout << 1;
    else if ((a[0] == 5 and a[1] == 5 and a[2] == 0 and a[3] == 0) or (a[0] == 0 and a[1] == 0 and a[2] == 5 and a[3] == 5) or (a[0] == 0 and a[1] == 5 and a[2] == 0 and a[3] == 5) or (a[0] == 5 and a[1] == 0 and a[2] == 5 and a[3] == 0) or (a[0] == 0 and a[1] == 5 and a[2] == 5 and a[3] == 0) or (a[0] == 5 and a[1] == 0 and a[2] == 0 and a[3] == 5))
        cout << 2;
    else
        cout << 1;
    return 0;
}