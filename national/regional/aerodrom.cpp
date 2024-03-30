#include <iostream>

using namespace std;

int main()
{

    int casovi, minuti, casovi2, minuti2;

    cin >> casovi >> minuti >> casovi2 >> minuti2;

    int rez = 0;

    while (casovi != casovi2 or minuti != minuti2)
    {
        if (casovi % 10 == minuti / 10 and minuti % 10 == casovi / 10)
            rez++;

        minuti++;

        if (minuti > 59)
        {
            minuti = 0;

            casovi++;
        }

        if (casovi > 23)
            casovi = 0;
    }

    if (casovi % 10 == minuti / 10 and minuti % 10 == casovi / 10)
        rez++;

    cout << rez;

    return 0;
}