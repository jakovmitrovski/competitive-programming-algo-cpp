#include <bits/stdc++.h>

using namespace std;

bool dali_e_prefix(string a, string b) /// dali a e prefix na b
{
    if (a.size() > b.size())
        return false;

    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return false;

    return true;
}

int main()
{
    int n;
    cin >> n;
    string niza[n + 2];
    for (int i = 0; i < n; i++)
        cin >> niza[i];

    for (int i = 0; i < n; i++)
    {
        string s = niza[i]; /// sakame da go najdeme najkratkiot prefiks koj ne e prefix na nekoj drug zbor

        string s1 = "";
        for (int j = 0; j < s.size(); j++)
        {
            s1 = s1 + s[j]; /// bukvata koja se naogja na j-tata pozicija vo s

            bool l = true;

            for (int k = 0; k < n; k++)
                if (k != i)
                {
                    /// dali s1 e prefix na zborot niza[k];

                    if (dali_e_prefix(s1, niza[k]) == true)
                    {
                        l = false;
                    }
                }

            if (l == true)
            {
                cout << s1 << endl;
                break;
            }
        }
    }
    return 0;
}