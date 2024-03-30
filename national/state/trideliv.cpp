#include <iostream>

using namespace std;

char smeni(int a)
{
    if (a == 1)
        return '1';
    if (a == 2)
        return '2';
    if (a == 3)
        return '3';
    if (a == 4)
        return '4';
    if (a == 5)
        return '5';
    if (a == 6)
        return '6';
    if (a == 7)
        return '7';
    if (a == 8)
        return '8';
    if (a == 9)
        return '9';
}

int vrati(char c)
{
    if (c == '1')
        return 1;
    if (c == '2')
        return 2;
    if (c == '3')
        return 3;
    if (c == '4')
        return 4;
    if (c == '5')
        return 5;
    if (c == '6')
        return 6;
    if (c == '7')
        return 7;
    if (c == '8')
        return 8;
    if (c == '9')
        return 9;
}

bool proveri(string s)
{
    int zbir = 0;

    for (int i = 0; i < s.size(); i++)
        zbir += vrati(s[i]);

    if (zbir % 3 == 0)
        return true;

    return false;
}

int main()
{
    string s, rez = "";

    cin >> s;

    for (int i = 0; i < s.size(); i++)
        for (int j = 9; j >= 1; j--)
        {
            string t = s;

            char p = smeni(j);

            if (p != t[i])
            {
                t[i] = p;

                if (proveri(t))
                    rez = max(t, rez);
            }
        }

    cout << rez << endl;

    return 0;
}