#include <iostream>

using namespace std;

int main()
{
    string s;

    cin >> s;

    long long rez = 1;

    int i = 0;

    while (i < s.size())
    {
        if (s[i] == 't' or s[i] == 'T')
        {
            rez *= 3;
            i += 8;
        }

        if (s[i] == 'd' or s[i] == 'D')
        {
            rez *= 2;
            i += 5;
        }

        if (s[i] == 'm' or s[i] == 'M')
        {
            rez -= 1;
            i += 5;
        }
    }

    cout << rez;

    return 0;
}