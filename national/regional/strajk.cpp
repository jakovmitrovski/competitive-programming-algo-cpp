#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    if (n >= 26)
    {
        cout << 3;
        return 0;
    }

    int k = n / 4, rez = 0;

    int rabotni_nedeli = 18 - k;

    if (rabotni_nedeli - n < 0)

        while (rabotni_nedeli - n < 0)

        {
            rabotni_nedeli += 7;

            rez++;
        }

    cout << rez;

    return 0;
}