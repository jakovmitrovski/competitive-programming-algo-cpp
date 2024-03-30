#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int mom = 7;
    string month = ". mart";

    if (n <= 24)
        cout << mom + n << month;

    else if (n > 24 && n <= 54)
    {
        n -= 24;
        month = ". april";
        cout << n << month;
    }
    else
    {
        n -= 54;
        cout << n << ". maj";
    }

    return 0;
}