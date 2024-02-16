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
    int rez = 0;
    for (int i = 0; i < n; i++)
    {
        int br = 0;
        while (a[i] == 1)
        {
            i++;
            br++;
        }
        if (br > rez)
            rez = br;
    }
    cout << rez;
    return 0;
}