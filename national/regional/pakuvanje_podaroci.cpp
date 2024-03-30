#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;

    cin >> n;

    int podaroci[n + 2];

    for (int i = 0; i < n; i++)
        cin >> podaroci[i];

    cin >> m;

    int kutii[m + 2];

    for (int i = 0; i < m; i++)
        cin >> kutii[i];

    int razlika = 99999999;
    int rez = -1;

    sort(podaroci, podaroci + n);
    sort(kutii, kutii + m);

    int i = 0, j = 0;

    while (i < n and j < m)
    {
        if (podaroci[i] > kutii[j])
            j++;
        else
        {
            if (kutii[j] - podaroci[i] <= razlika)
            {
                razlika = kutii[j] - podaroci[i];
                rez = podaroci[i];
            }
            i++;
        }
    }

    cout << rez;

    return 0;
}