#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;

    cin >> s;

    for (int i = 0; i < s.size();)
    {
        char c = s[i];
        int br = 0;
        while (c == s[i])
        {
            i++;
            br++;
        }

        cout << br << c;
    }

    return 0;
}