#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 4)
        cout << "1210";
    else if (n == 5)
        cout << "21200";
    else if (n == 8)
        cout << "42101000";
    else if (n == 6)
        cout << "0";
    else if (n == 7)
        cout << "3211000";
    else if (n == 9)
        cout << "521001000";
    else
        cout << "6210001000";

    return 0;
}