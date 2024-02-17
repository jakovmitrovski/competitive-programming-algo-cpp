#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string a;
    int a1[10002], b[10002], nizica[100002], pom = 0;
    cin >> a;

    for (int i = 0; i < a.size(); i++)
    {
        a1[i] = a[i] - 48;
        b[i] = a1[i];
    }

    sort(a1, a1 + a.size());
    sort(b, b + a.size());
    reverse(b, b + a.size());

    int br = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a1[i] == b[i])
        {
            br++;

            if (br == a.size())
            {
                cout << 0;
                return 0;
            }
        }
    }

    for (int i = a.size() - 1; i > -1; i--)
    {
        if (b[i - 1] < 0)
        {
            b[i - 1] += 10;
            b[i - 2] -= 1;
        }
        if (b[i] < a1[i])
        {
            b[i] += 10;
            b[i - 1] -= 1;

            if (b[i - 1] < 0)
            {
                b[i - 1] += 10;
                b[i - 2] -= 1;
            }
        }
        nizica[i] = b[i] - a1[i];
    }

    while (nizica[pom] == 0)
        pom++;

    if (pom == a.size())
        cout << 0;

    else
        for (int i = pom; i < a.size(); i++)
            cout << nizica[i];

    return 0;
}