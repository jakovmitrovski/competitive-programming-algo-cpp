#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> v1;

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;

        cin >> a;

        v.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        int a;

        cin >> a;

        v1.push_back(a);
    }

    int i = 0, j = 0, rez = 0;

    while (v != v1)
    {
        if (v[i] < v1[i])
        {
            j = i;

            while (v[j] < v1[j] and j < v.size())
            {
                v[j] += 1;

                j++;
            }

            rez++;
        }

        if (v[i] > v1[i])
        {
            j = i;

            while (v[j] > v1[j] and j < v1.size())
            {
                v[j] -= 1;

                j++;
            }

            rez++;
        }

        if (v[i] == v1[i])
            i++;

        if (i == v.size())
            i = 0;
    }

    cout << rez;

    return 0;
}