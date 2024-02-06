#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }
    int c = 0;
    c = (a[0][0] * 3) + a[0][1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int zbir = 0;
            zbir += (a[i][0] * 3) + a[i][1];
            if (zbir > c)
                c = zbir;
        }
    }
    cout << c;
    return 0;
}