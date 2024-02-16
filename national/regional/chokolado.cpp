#include <iostream>
#include <string>
using namespace std;

int main()
{
    string chokolado;
    cin >> chokolado;

    char bukva;
    cin >> bukva;

    int rezultat = 0;

    for (int i = 0; i < (int)chokolado.size(); i++)
    {
        if (chokolado[i] == bukva) // od tuka pocnuva delot
        {
            int pocetok = i;
            int kraj = i;

            while ((kraj + 1 < chokolado.size()) && (chokolado[kraj + 1] == bukva))
                kraj++;

            if (pocetok > 0) // treba da skrshime od levo
                rezultat++;

            if (kraj + 1 < chokolado.size()) // treba da skrshime od desno
                rezultat++;

            i = kraj; // prodolzi da barash novi delcinja posle ova
        }
    }

    cout << rezultat << endl;
    return 0;
}