#include <iostream>

using namespace std;

int main()
{
    int prvi_sto, sledni, kolku_treba;

    cin >> prvi_sto >> sledni >> kolku_treba;

    int a = prvi_sto, br = 0, rez = 0;

    while (prvi_sto < kolku_treba)
    {
        prvi_sto += a;

        br++;

        if (prvi_sto == 100 * a)

            break;
    }

    while (prvi_sto + sledni < kolku_treba)
    {
        rez++;

        prvi_sto += sledni;
    }
    int b = kolku_treba - prvi_sto;

    while (b > 0)
    {

        b -= sledni;

        rez++;
    }
    rez += br;
    cout << rez + 1;
    return 0;
}