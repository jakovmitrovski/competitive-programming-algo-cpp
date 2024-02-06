#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int rez = 0, res = 0;
    for (int i = a; i <= b; i++)
    {
        int c = 1, br = 0;

        while (c <= i)
        {
            if (i % c == 0)
                br++;
            c++;
        }

        if (br > rez)
        {
            rez = br;
            res = i;
        }
    }
    cout << res << " " << rez;
    return 0;
}