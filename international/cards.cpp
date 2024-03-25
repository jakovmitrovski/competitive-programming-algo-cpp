#include <bits/stdc++.h>

using namespace std;

void pecati_broj(vector<int> a, vector<int> b)
{
    for (int i = a.size() - 1, j = b.size() - 1; i >= 0; i--)
    {
        cout << a[i];

        if (j < 0)
            return;

        cout << b[j--];
    }
}

int main()
{
    int t;

    cin >> t;

    while (t > 0)
    {
        int n;

        cin >> n;

        vector<int> parni, neparni;

        for (int i = 0; i < n; i++)
        {
            int a;

            cin >> a;

            if (a % 2 == 0)
                parni.push_back(a);

            else
                neparni.push_back(a);
        }

        sort(parni.begin(), parni.end());
        sort(neparni.begin(), neparni.end());

        if (parni.size() == 0)
            cout << neparni[neparni.size() - 1];

        else if (neparni.size() == 0)
            cout << parni[parni.size() - 1];

        else if (parni[parni.size() - 1] > neparni[neparni.size() - 1] && parni.size() == neparni.size())
            pecati_broj(parni, neparni);

        else if (parni[parni.size() - 1] < neparni[neparni.size() - 1] && parni.size() == neparni.size())
            pecati_broj(neparni, parni);

        else if (parni.size() < neparni.size())
            pecati_broj(neparni, parni);

        else
            pecati_broj(parni, neparni);

        t--;

        cout << endl;
    }

    return 0;
}