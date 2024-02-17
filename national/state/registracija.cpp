#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int n;
    cin >> n;
    string stringac[n + 2];

    string s1;

    int br = 0;

    for (int i = 1; i <= 9; i++)
        s1 += i + 48;

    for (int i = 0; i < n; i++)
        cin >> stringac[i];

    for (int i = 0; i < n; i++)
    {
        if (s == stringac[i])
            br++;
    }

    if (br == 0)
    {
        cout << s;

        return 0;
    }

    string rez = s;

    string rez1 = s;

    string rez2 = s;

    string rez3 = s;

    string rez4 = s;

    string rez5 = s;

    string rez6 = s;

    string rez7 = s;

    string rez8 = s;

    string rez9 = s;

    string rez10 = s;

    for (int i = 0; i < n; i++)
    {
        if (s == stringac[i])

            for (int j = 0; j < 9; j++)
            {

                s += s1[j];

                for (int k = 0; k < n; k++)

                    if (s == stringac[k])
                    {
                        s = rez;
                        break;
                    }

                if (s != rez)
                {
                    cout << s;

                    return 0;
                }
            }
    }

    string s2;

    for (int i = 0; i <= 9; i++)
        s2 += i + 48;

    rez += '1';

    s += '1';

    for (int i = 0; i < n; i++)
    {
        if (s == stringac[i])

            for (int j = 0; j <= 9; j++)
            {

                s += s2[j];

                for (int k = 0; k < n; k++)

                    if (s == stringac[k])
                    {
                        s = rez;
                        break;
                    }

                if (s != rez)
                {

                    cout << s;
                    return 0;
                }
            }
    }

    string s3;

    for (int i = 0; i <= 9; i++)
        s3 += i + 48;

    rez1 += '2';

    rez2 += '2';

    for (int i = 0; i < n; i++)
    {
        if (rez2 == stringac[i])

            for (int j = 0; j <= 9; j++)
            {

                rez2 += s3[j];

                for (int k = 0; k < n; k++)

                    if (rez2 == stringac[k])
                    {
                        rez2 = rez1;
                        break;
                    }

                if (rez2 != rez1)
                {

                    cout << rez2;
                    return 0;
                }
            }
    }

    string s4;

    for (int i = 0; i <= 9; i++)
        s4 += i + 48;

    rez3 += '3';

    rez4 += '3';

    for (int i = 0; i < n; i++)
    {
        if (rez4 == stringac[i])

            for (int j = 0; j <= 9; j++)
            {

                rez4 += s3[j];

                for (int k = 0; k < n; k++)

                    if (rez4 == stringac[k])
                    {
                        rez4 = rez3;
                        break;
                    }

                if (rez4 != rez3)
                {

                    cout << rez4;
                    return 0;
                }
            }
    }

    string s5;

    for (int i = 0; i <= 9; i++)
        s5 += i + 48;

    rez5 += '4';

    rez6 += '4';

    for (int i = 0; i < n; i++)
    {
        if (rez6 == stringac[i])

            for (int j = 0; j <= 9; j++)
            {

                rez6 += s3[j];

                for (int k = 0; k < n; k++)

                    if (rez6 == stringac[k])
                    {
                        rez6 = rez5;
                        break;
                    }

                if (rez6 != rez5)
                {

                    cout << rez6;
                    return 0;
                }
            }
    }

    string s6;

    for (int i = 0; i <= 9; i++)
        s6 += i + 48;

    rez7 += '5';

    rez8 += '5';

    for (int i = 0; i < n; i++)
    {
        if (rez8 == stringac[i])

            for (int j = 0; j <= 9; j++)
            {

                rez8 += s3[j];

                for (int k = 0; k < n; k++)

                    if (rez8 == stringac[k])
                    {
                        rez8 = rez7;
                        break;
                    }

                if (rez8 != rez7)
                {

                    cout << rez8;
                    return 0;
                }
            }
    }

    string s7;

    for (int i = 0; i <= 9; i++)
        s7 += i + 48;

    rez9 += '6';

    rez10 += '6';

    for (int i = 0; i < n; i++)
    {
        if (rez10 == stringac[i])

            for (int j = 0; j <= 9; j++)
            {

                rez10 += s3[j];

                for (int k = 0; k < n; k++)

                    if (rez10 == stringac[k])
                    {
                        rez10 = rez9;
                        break;
                    }

                if (rez10 != rez9)
                {

                    cout << rez10;
                    return 0;
                }
            }
    }

    return 0;
}