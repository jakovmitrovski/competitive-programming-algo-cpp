#include <iostream>
using namespace std;

bool dali(int c, int r, int figura_c[], int figura_r[], int n)
{
    for (int i = 0; i < n; i++)
        if ((c == figura_c[i]) and (r == figura_r[i]))
            return true;
    return false;
}

int main()
{
    char ch;
    int r, c;
    cin >> ch >> r;
    c = (ch - 'a') + 1;
    int n;
    cin >> n;
    int figura_c[20];
    int figura_r[20];
    for (int i = 0; i < n; i++)
    {
        char fc;
        int fr;
        cin >> fc >> fr;
        figura_r[i] = fr;
        figura_c[i] = (fc - 'a') + 1;
    }
    int rez = 0;
    if (dali(c - 2, r - 1, figura_c, figura_r, n))
        rez++;
    if (dali(c - 2, r + 1, figura_c, figura_r, n))
        rez++;
    if (dali(c - 1, r - 2, figura_c, figura_r, n))
        rez++;
    if (dali(c - 1, r + 2, figura_c, figura_r, n))
        rez++;
    if (dali(c + 2, r - 1, figura_c, figura_r, n))
        rez++;
    if (dali(c + 2, r + 1, figura_c, figura_r, n))
        rez++;
    if (dali(c + 1, r - 2, figura_c, figura_r, n))
        rez++;
    if (dali(c + 1, r + 2, figura_c, figura_r, n))
        rez++;
    cout << rez << endl;
    return 0;
}