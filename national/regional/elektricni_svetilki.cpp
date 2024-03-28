#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char promena(char a)
{
    if (a == 'Y')
        return 'N';
    return 'Y';
}

int main()
{

    string s;
    cin >> s;
    int rez = 0;

    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'Y')
        {
            for (int j = i; j < s.size(); j += i + 1)
                s[j] = promena(s[j]);

            rez++;
        }
    cout << rez;

    return 0;
}