#include <iostream>

using namespace std;

int main()
{
    int n, k;

    cin >> n >> k;

    int rez = 0;

    while (k > 0)
    {
        if (k - n >= 0)
        {
            k += 3;
            rez++;
        }

        k -= n;
    }

    cout << rez;

    return 0;
}