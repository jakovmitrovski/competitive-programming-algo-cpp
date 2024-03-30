#include <bits/stdc++.h>

using namespace std;

vector<int> prosti;
bool sito[1000002];
int rez = 0;
bool visited[1000002];
string s;

int znak(char a)
{
    if (a == '0')
        return 0;

    if (a == '1')
        return 1;

    if (a == '2')
        return 2;

    if (a == '3')
        return 3;

    if (a == '4')
        return 4;

    if (a == '5')
        return 5;

    if (a == '6')
        return 6;

    if (a == '7')
        return 7;

    if (a == '8')
        return 8;

    if (a == '9')
        return 9;
}

int stepen(int broj, int stp)
{
    if (stp == 0)
        return 1;

    return broj * stepen(broj, stp - 1);
}

int napraj_broj(int a, int b)
{
    string s1 = "";

    for (int i = a; i <= b; i++)
        s1 += s[i];

    // cout << "string e " << s1 << endl;

    reverse(s1.begin(), s1.end());

    int broj = 0;

    for (int i = 0; i < s1.size(); i++)
        broj += znak(s1[i]) * stepen(10, i);

    // cout << "brojot e " << broj << endl;

    // system("pause");

    return broj;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s;

    sito[1] = true;

    for (long long i = 2; i <= 1000000; i++)
        if (sito[i] == false)
            for (long long j = i * i; j <= 1000000; j += i)
                sito[j] = true;

    for (long long i = 2; i <= 1000000; i++)
        if (sito[i] == false)
            prosti.push_back(i);

    for (int k = 0; k < 6; k++)
    {
        if (k > s.size())
            break;

        for (int i = 0; i < s.size() - k; i++)
            if (s[i] != '0')
            {
                int n = napraj_broj(i, i + k);

                if (sito[n] == false and visited[n] == false)
                {
                    rez++;
                    visited[n] = true;
                }
            }
    }

    cout << rez;

    return 0;
}