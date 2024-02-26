#include <iostream>

using namespace std;

int funkcija(int niza[], int n)
{
    int najgolem = niza[0];

    for (int i = 0; i < n; i++)
        if (najgolem < niza[i])
            najgolem = niza[i];

    return najgolem;
}

int funkcija1(int niza[], int n)
{
    int najmal = niza[0];

    for (int i = 0; i < n; i++)
        if (najmal > niza[i])
            najmal = niza[i];

    return najmal;
}

int main()
{
    int n;

    cin >> n;

    int br = 0;

    int niza[n + 2];

    for (int i = 0; i < n; i++)
        cin >> niza[i];

    int zbir = 0;

    for (int i = 0; i < n; i++)
        zbir += niza[i];

    if (zbir % n != 0)
    {
        cout << "GRESHKA";

        return 0;
    }

    int rez = 0;

    while (true)
    {
        int najgolem = funkcija(niza, n);

        int najmal = funkcija1(niza, n);

        for (int j = 0; j < n; j++)
            if (niza[j] == najgolem and niza[j] > zbir / n)
            {
                niza[j]--;
                break;
            }

        for (int c = 0; c < n; c++)
            if (niza[c] == najmal and niza[c] < zbir / n)
            {
                niza[c]++;
                break;
            }

        rez++;

        int br = 0;

        for (int i = 0; i < n; i++)
            if (niza[i] == zbir / n)
                br++;

        if (br == n)
            break;
    }

    cout << rez << endl;

    return 0;
}