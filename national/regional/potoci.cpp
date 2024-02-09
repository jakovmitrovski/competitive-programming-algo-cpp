#include <iostream>

using namespace std;

int slenda_vrednost_za_potok1_3_9(int potok_pom)
{
    int rez = potok_pom;

    while (potok_pom > 0)
    {
        rez += potok_pom % 10;
        potok_pom /= 10;
    }

    return rez;
}

int main()
{
    int potok;
    cin >> potok;

    int potok1 = 1, potok3 = 3, potok9 = 9;

    while ((potok != potok1) and (potok != potok3) and (potok != potok9))
    {
        while (potok1 < potok)
            potok1 = slenda_vrednost_za_potok1_3_9(potok1);

        while (potok3 < potok)
            potok3 = slenda_vrednost_za_potok1_3_9(potok3);

        while (potok9 < potok)
            potok9 = slenda_vrednost_za_potok1_3_9(potok9);

        if ((potok != potok1) && (potok != potok3) && (potok != potok9))
            potok = slenda_vrednost_za_potok1_3_9(potok);
    }

    if (potok1 == potok)
        cout << "1"
             << " " << potok << endl;
    if (potok3 == potok)
        cout << "3"
             << " " << potok << endl;
    if (potok9 == potok)
        cout << "9"
             << " " << potok << endl;

    return 0;
}