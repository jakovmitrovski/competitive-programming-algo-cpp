#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    int najgolem, momentalen;
    for (int i = 1000; i < 10000; i++)
    {
        momentalen = i;
        int temp = m;
        int tempBroj = i;
        for (int i = 0; i < 4; i++)
        {
            int c = 0;
            c = tempBroj % 10;
            tempBroj = tempBroj / 10;
            switch (c)
            {
            case 1:
                temp -= 3;
                break;
            case 2:
                temp -= 5;
                break;
            case 3:
                temp -= 5;
                break;
            case 4:
                temp -= 4;
                break;
            case 5:
                temp -= 5;
                break;
            case 6:
                temp -= 5;
                break;
            case 7:
                temp -= 3;
                break;
            case 8:
                temp -= 7;
                break;
            case 9:
                temp -= 5;
                break;
            case 0:
                temp -= 6;
                break;
            }
        }
        if (temp == 0)
            najgolem = momentalen;
    }
    if (najgolem <= 9999 && najgolem >= 1000)
        cout << najgolem;
    else
        cout << "-1";
    return 0;
}
