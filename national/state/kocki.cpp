#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int rez = min(n, m);
    if (((rez * rez) % 2) != 0)
        rez -= 1;
    cout << (rez * rez) << endl;
    return 0;
}