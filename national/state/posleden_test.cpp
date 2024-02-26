#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int pom = 0;
    if (n == 2)
    {
        int g = (a + b + c + d + pom) / 5;
        if (g < 60)
        {
            while (g < 60)
            {
                pom++;
                g = (a + b + c + d + pom) / 5;
            }
            if (pom > 100)
            {
                cout << "GRESHKA";
                return 0;
            }
            cout << pom;
            return 0;
        }
        else
        {
            cout << 0;
            return 0;
        }
    }
    int br = 0;
    if (n == 3)
    {
        int h = (a + b + c + d + br) / 5;
        if (h < 70)
        {
            while (h < 70)
            {
                br++;
                h = (a + b + c + d + br) / 5;
            }
            if (br > 100)
            {
                cout << "GRESHKA";
                return 0;
            }
            cout << br;
            return 0;
        }
        else
        {
            cout << 0;
            return 0;
        }
    }
    int gr = 0;
    if (n == 4)
    {
        int j = (a + b + c + d + gr) / 5;
        if (j < 80)
        {
            while (j < 80)
            {
                gr++;
                j = (a + b + c + d + gr) / 5;
            }
            if (gr > 100)
            {
                cout << "GRESHKA";
                return 0;
            }
            cout << gr;
            return 0;
        }
        else
        {
            cout << 0;
            return 0;
        }
    }
    int ar = 0;
    if (n == 5)
    {
        int k = (a + b + c + d + ar) / 5;
        if (k < 90)
        {
            while (k < 90)
            {
                ar++;
                k = (a + b + c + d + ar) / 5;
            }
            if (ar > 100)
            {
                cout << "GRESHKA";
                return 0;
            }
            cout << ar;
            return 0;
        }
        else
        {
            cout << 0;
            return 0;
        }
    }
    if (ar > 100 or pom > 100 or gr > 100 or br > 100)
        cout << "GRESHKA";
    return 0;
}