#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        int val = s[i] - 'a';

        if (val + n >= 26)
        {
            int x = n - (25 - val);
            val = 25;

            s[i] = (val - ((val + x) % 25) + 'a');
        }
        else
        {
            s[i] = (s[i] - 'a' + n) + 'a';
        }
    }

    cout << s << endl;

    return 0;
}