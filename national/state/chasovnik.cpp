#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m1, m2, s1, s2;

    cin >> m1 >> s1 >> m2 >> s2;

    int rez = 0, rez1 = 0, rez2 = 0, rez3 = 0;

    while (true)
    {
        int a = s1, b = s1;
        int x = m1, y = m1;

        while (a != s2)
        {
            a++;
            rez++;

            if (a == 60)
            {
                a = 0;
                x++;

                if (x == 24)
                    x = 0;
            }
        }

        while (x != m2)
        {
            x++;
            rez++;

            if (x == 24)
                x = 0;
        }

        if (x == m2 and a == s2)
            break;
    }

    while (true)
    {
        int a = s1, b = s1;
        int x = m1, y = m1;

        while (a != s2)
        {
            a--;
            rez1++;

            if (a == -1)
            {
                a = 59;
                x--;

                if (x == -1)
                    x = 23;
            }
        }

        while (x != m2)
        {
            x++;
            rez1++;

            if (x == 24)
                x = 0;
        }

        if (x == m2 and a == s2)
            break;
    }

    while (true)
    {
        int a = s1, b = s1;
        int x = m1, y = m1;

        while (a != s2)
        {
            a++;
            rez2++;

            if (a == 60)
            {
                a = 0;
                x++;

                if (x == 24)
                    x = 0;
            }
        }

        while (x != m2)
        {
            x--;
            rez2++;

            if (x == -1)
                x = 23;
        }

        if (x == m2 and a == s2)
            break;
    }

    while (true)
    {
        int a = s1, b = s1;
        int x = m1, y = m1;

        while (a != s2)
        {
            a--;
            rez3++;

            if (a == -1)
            {
                a = 59;
                x--;

                if (x == -1)
                    x = 23;
            }
        }

        while (x != m2)
        {
            x--;
            rez3++;

            if (x == -1)
                x = 23;
        }

        if (x == m2 and a == s2)
            break;
    }

    cout << min(min(rez, rez1), min(rez2, rez3));

    return 0;
}