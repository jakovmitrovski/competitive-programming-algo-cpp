#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

// 01234567891011121314
//?????-(?-( ? + ? ) )
// 33333333
int main()
{
    string s, x;
    int i, j;

    cin >> s >> x;
    vector<int> brojki;
    for (i = x.size() - 1; i >= 0; i--)
    {
        int a = x[i] - '0';
        brojki.push_back(a);
    }
    sort(brojki.begin(), brojki.end());
    reverse(brojki.begin(), brojki.end());
    int from, to;
    for (i = 1; i < s.size(); i++)
    {
        if (s[i] == '?' && s[i - 1] == '(')
        {
            s.insert(i, "+");
            i++;
        }
    }
    if (s[0] == '?')
        s.insert(0, "+");
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            to = i;
            for (j = to;; j--)
            {
                if (s[j] == '(')
                {
                    from = j;
                    break;
                }
            }
            if (s[from - 1] == '-')
                for (j = from; j <= to; j++)
                {
                    if (s[j] == '+')
                    {
                        s[j] = '-';
                        continue;
                    }
                    if (s[j] == '-')
                    {
                        s[j] = '+';
                    }
                }
            s.erase(to, 1);
            s.erase(from, 1);
            s.erase(from, 1);
            i--;
            i--;
            i--;
        }
    }
    int plus[8], minus[8];
    memset(plus, 0, sizeof(plus));
    memset(minus, 0, sizeof(minus));

    for (i = 0; i < s.size(); i++)
    {
        int tmp = -1;
        if (s[i] == '?')
        {
            for (j = i;; j++)
            {
                tmp++;
                if (s[j] != '?')
                    break;
            }
        }
        if (s[i - 1] == '+')
        {
            for (j = tmp; j >= 1; j--)
            {
                plus[j]++;
            }
        }
        if (s[i - 1] == '-')
        {
            for (j = tmp; j >= 1; j--)
            {
                minus[j]++;
            }
        }
    }

    long long res = 0;
    j = 0;
    for (i = 7; i >= 1; i--)
    {
        while (plus[i] > 0)
        {
            plus[i]--;
            res += (brojki[j] * pow(10, i));
            j++;
        }
    }
    j = brojki.size() - 1;
    for (i = 7; i >= 1; i--)
    {
        while (minus[i] > 0)
        {
            minus[i]--;
            res -= (brojki[j] * pow(10, i));
            j--;
        }
    }
    cout << res / 10 << endl;

    return 0;
}