#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> v;

    int rez = 0;

    for (int i = 0; i < n; i++)
    {
        int a;

        cin >> a;

        v.push_back(a);
    }

    if (v[0] != 0)
        rez++;

    for (int i = 1; i < n; i++)
    {
        if (v[i] == 0)
            continue;

        else if (v[i] == 3)
        {
            rez++;

            if (v[i - 1] == 1)
                v[i] = 2;

            else if (v[i - 1] == 2)
                v[i] = 1;
        }

        else if (v[i - 1] == v[i])
            v[i] = -1;

        else if (v[i - 1] != v[i])
            rez++;
    }

    cout << rez;

    return 0;
}