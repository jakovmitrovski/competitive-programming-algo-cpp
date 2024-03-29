#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 2];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int rez = 0, rez1 = 0, c;
    for (int i = 0; i < n; i++)
    {
        int br = 0, gr = 0;
        while (a[i] > 0)
        {
            c = a[i] % 10;
            a[i] /= 10;
            gr++;
            if (c % 2 == 0)
                br++;
        }
        if (br == gr)
            rez += br;
        if (br == gr)
            rez1++;
    }
    cout << rez1 << endl;
    cout << rez;
    return 0;
}