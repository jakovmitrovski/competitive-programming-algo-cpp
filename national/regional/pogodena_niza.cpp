#include <iostream>

using namespace std;

int main()
{
    int n;

    string s;

    cin >> n >> s;

    int flag = 0, bra = 0, brb = 0, pogodena = 0, brojac = 0;

    for (int i = 0; i < n; i++)
    {
        if (flag)
        {
            if (s[i] == 'A')
                bra++;
            if (s[i] == 'B')
                brb++;
        }

        if (s[i] == 'C' and flag == 0)
        {
            flag = 1;
            continue;
        }

        if (s[i] == 'C')
        {
            if (bra > brb)
            {
                bra = 0;
                brb = 0;
                continue;
            }

            else
            {
                pogodena = 1;
                brojac++;
                bra = 0;
                brb = 0;
            }
        }
    }

    if (!pogodena)
        cout << "POGODENA";

    else
        cout << brojac;

    return 0;
}