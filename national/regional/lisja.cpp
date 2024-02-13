#include <iostream>

using namespace std;

int main()
{
    int a[32][5];
    for (int i = 0; i < 30; i++)
        for (int j = 0; j < 2; j++)
            cin >> a[i][j];
    int c = a[0][1];
    int rez = 1;
    for (int i = 0; i < 30; i++)
    {
        if (a[i][1] > c)
        {
            c = a[i][1];
            rez = a[i][0];
        }
    }
    cout << rez << " "
         << "noemvri";
    return 0;
}