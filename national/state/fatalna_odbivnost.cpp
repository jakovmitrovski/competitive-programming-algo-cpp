#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int niza[n + 2];

    for (int i = 0; i < n; i++)
        cin >> niza[i];

    int rez = 0;

    for (int i = 0; i < n; i++)
        if (niza[i] == 1)
        {
            int br = 0;

            for (int j = i + 1; j < n; j++)
                if (niza[j] == 2)
                    br++;

            rez += br;
        }

    cout << rez;

    return 0;
}