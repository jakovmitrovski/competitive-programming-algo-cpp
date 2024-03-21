#include <bits/stdc++.h>

using namespace std;

int s1, s2;
string x;
string s5;
bool l;
int rez = 0;

char smeni(int b)
{
    if (b == 0)
        return '0';
    if (b == 1)
        return '1';
    if (b == 2)
        return '2';
    if (b == 3)
        return '3';
    if (b == 4)
        return '4';
    if (b == 5)
        return '5';
    if (b == 6)
        return '6';
    if (b == 7)
        return '7';
    if (b == 8)
        return '8';
    if (b == 9)
        return '9';
}

string napravi_string(int a)
{
    string s = "";

    if (a == 0)
        return "0";

    while (a > 0)
    {
        int c = a % 10;

        char p = smeni(c);

        s += p;

        a /= 10;
    }

    reverse(s.begin(), s.end());

    return s;
}

string sklopi_x_cifren(int a, int b)
{
    string s = "";

    for (int i = a; i <= b; i++)
        s += s5[i];

    // cout << "Dali se " << x << " i " << s << " ednakvi " << endl;

    // system("pause");

    return s;
}

int main()
{
    cin >> s1 >> s2 >> x;

    if (x == "0")
    {
        cout << 1;
        return 0;
    }

    for (int i = s1; i <= s2; i++)
    {
        l = false;
        s5 = napravi_string(i);

        // cout << "Vlaga za " << s5 << endl;

        if (s5.size() >= x.size())
        {
            for (int j = 0; j <= s5.size() - x.size(); j++)
                if (s5[j] != '0')
                {
                    string s3 = sklopi_x_cifren(j, j + x.size() - 1);

                    if (s3 == x)
                    {
                        rez++;
                        l = true;
                        // cout << "go zgolemuva poso go najde " << x << " vo " << s5 << endl;
                    }

                    if (l == true)
                        break;
                }
        }
    }

    cout << rez;

    return 0;
}