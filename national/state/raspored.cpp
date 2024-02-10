#include <iostream>

using namespace std;

int main()
{
    float n, a, b;

    cin >> n >> a >> b;

    int niza[100002], suma = 0, rez = 0;

    for (int i = 0; i < n; i++)
        cin >> niza[i];

    for (int i = 0; i < n; i++)
        suma += niza[i];

    if ((suma / n) > b or (suma / n) < a)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; i++)
        if (niza[i] > b)
            for (int j = 0; j < n; j++)
                if (niza[j] < a)
                {
                    int manjak = a - niza[j];
                    int visok = niza[i] - b;

                    if (manjak >= visok)
                    {
                        niza[i] -= visok;
                        niza[j] += visok;
                        rez += visok;
                        break;
                    }

                    else
                    {
                        niza[i] -= manjak;
                        niza[j] += manjak;
                        rez += manjak;
                    }
                }

    for (int i = 0; i < n; i++)
        if (niza[i] > b)
            for (int j = 0; j < n; j++)
                if (niza[j] < b)
                {
                    int prazno_mesto = b - niza[j];
                    int visok = niza[i] - b;

                    if (prazno_mesto >= visok)
                    {
                        niza[i] -= visok;
                        niza[j] += visok;
                        rez += visok;
                        break;
                    }
                    else
                    {
                        niza[i] -= prazno_mesto;
                        niza[j] += prazno_mesto;
                        rez += prazno_mesto;
                    }
                }

    int moze_da_zemam = 0, mi_trebaat = 0;

    for (int i = 0; i < n; i++)
    {
        if (niza[i] < a)
            mi_trebaat += (a - niza[i]);

        else
            moze_da_zemam += (niza[i] - a);
    }

    if (moze_da_zemam < mi_trebaat)
        cout << -1 << endl;

    else
        cout << rez + mi_trebaat << endl;

    return 0;
}