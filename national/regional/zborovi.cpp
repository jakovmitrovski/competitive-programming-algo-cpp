#include <iostream>
#include <vector>

using namespace std;

vector<pair<char, int>> v;

char golema(char c)
{
    if (c == 'a')
        return 'A';
    if (c == 'b')
        return 'B';
    if (c == 'c')
        return 'C';
    if (c == 'd')
        return 'D';
    if (c == 'e')
        return 'E';
    if (c == 'f')
        return 'F';
    if (c == 'g')
        return 'G';
    if (c == 'h')
        return 'H';
    if (c == 'i')
        return 'I';
    if (c == 'j')
        return 'J';
    if (c == 'k')
        return 'K';
    if (c == 'l')
        return 'L';
    if (c == 'm')
        return 'M';
    if (c == 'n')
        return 'N';
    if (c == 'o')
        return 'O';
    if (c == 'p')
        return 'P';
    if (c == 'q')
        return 'Q';
    if (c == 'r')
        return 'R';
    if (c == 's')
        return 'S';
    if (c == 't')
        return 'T';
    if (c == 'u')
        return 'U';
    if (c == 'v')
        return 'V';
    if (c == 'w')
        return 'W';
    if (c == 'x')
        return 'X';
    if (c == 'y')
        return 'Y';
    if (c == 'z')
        return 'Z';
}

int vrednost(char a)
{
    for (int i = 0; i < v.size(); i++)
        if (v[i].first == a)
            return v[i].second;
}

int main()
{
    for (int i = 0; i < 26; i++)
    {
        char a;
        int b;
        cin >> a >> b;
        pair<char, int> par;
        par.first = a;
        par.second = b;

        v.push_back(par);

        par.first = golema(a);
        par.second = b + 20;

        v.push_back(par);
    }

    int n;
    cin >> n;

    string niza[n + 2];

    for (int i = 0; i < n; i++)
        cin >> niza[i];

    int rez = 0;
    string res;

    for (int i = 0; i < n; i++)
    {
        string s = niza[i];
        int sum = 0;

        for (int j = 0; j < s.size(); j++)
        {
            // cout<<"vrednosta na "<<s[j]<<" e "<<vrednost(s[j])<<endl;
            sum += vrednost(s[j]);
        }

        if (sum > rez)
        {
            rez = sum;
            res = s;
        }

        // cout<<"za s="<<s<<" rez = "<<rez<<endl;
    }

    cout << res << endl;
    return 0;
}