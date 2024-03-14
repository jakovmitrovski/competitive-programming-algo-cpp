#include <bits/stdc++.h>

using namespace std;

int golemina = 0;

string pomnozi(string a, string b)
{
    string s;
    vector<string> n, m;

    int k = b.size();

    for (int i = a.size() - 1; i >= 0; i--)
    {
        string s1 = "0";

        for (int j = 0; j <= b.size(); j++)
            s1 += '0';

        for (int j = b.size() - 1; j >= 0; j--)
        {
            int k = a[i] - 48;

            int q = b[j] - 48;

            k *= q;

            s1[j + 1] += (k % 10);

            s1[j] += (k / 10);

            while (s1[j + 1] > '9')
            {
                s1[j + 1] -= 10;

                s1[j]++;
            }

            while (s1[j] > '9')
            {
                s1[j - 1]++;

                s1[j] -= 10;
            }
        }

        string stringac;

        for (int j = 0; j <= k + 3; j++)
            stringac += '0';

        s1 = stringac + s1;

        int size1 = s1.size();

        golemina = max(golemina, size1);

        while (s1.size() < golemina - 1)
            s1 += '0';

        k--;

        n.push_back(s1);
    }

    s = n[0];

    s.resize(golemina * golemina);

    for (int i = 1; i < n.size(); i++)
    {
        string s1 = n[i];

        for (int j = n[i].size() - 1; j > 0; j--)
        {
            if (s[j] > '9')
            {
                s[j] -= 10;

                s[j - 1]++;
            }

            s[j] += s1[j] - 48;

            if (s[j] > '9')
            {
                s[j] -= 10;

                s[j - 1]++;
            }
            if (s[j - 1] > '9')
            {
                s[j - 2]++;

                s[j - 1] -= 10;
            }
        }
    }

    return s;
}

int main()
{
    int m = 0;

    int niza[10];

    vector<int> v;

    for (int i = 1; i <= 9; i++)
    {
        cin >> niza[i];

        m += niza[i];
    }

    for (int i = 1; i <= 9; i++)
        for (int j = 0; j < niza[i]; j++)
            v.push_back(i);

    reverse(v.begin(), v.end());

    string prv = "", vtor = "";

    prv += v[0] + 48;

    for (int i = 1; i < v.size(); i++)
    {
        if (prv.size() < vtor.size())
            prv += v[i] + 48;

        else if (prv.size() > vtor.size())
            vtor += v[i] + 48;

        else
        {
            if (prv > vtor)
                vtor += v[i] + 48;

            else
                prv += v[i] + 48;
        }
    }

    string s = pomnozi(prv, vtor);

    bool okej = false;

    for (int i = 0; i < golemina - 1; i++)
    {
        if (s[i] != '0')
            okej = true;

        if (okej == true)
            cout << s[i];
    }

    return 0;
}