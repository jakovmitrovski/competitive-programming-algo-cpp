#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

int main()
{
    int n, rez = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        pair<int, int> par;
        par.first = a;
        par.second = b;

        v.push_back(par);
    }

    for (int i = 0; i < n; i++)
    {
        int eden = 0, dva = 0, tri = 0, cetiri = 0, pet = 0, shest = 0, sedum = 0, osum = 0, devet = 0;
        int eden1 = 0, dva1 = 0, tri1 = 0, cetiri1 = 0, pet1 = 0, shest1 = 0, sedum1 = 0, osum1 = 0, devet1 = 0;
        while (v[i].first > 0 and v[i].second > 0)
        {
            int c = v[i].first % 10;
            int d = v[i].second % 10;
            if (c == 1)
                eden++;
            if (c == 2)
                dva++;
            if (c == 3)
                tri++;
            if (c == 4)
                cetiri++;
            if (c == 5)
                pet++;
            if (c == 6)
                shest++;
            if (c == 7)
                sedum++;
            if (c == 8)
                osum++;
            if (c == 9)
                devet++;
            v[i].first /= 10;

            if (d == 1)
                eden1++;
            if (d == 2)
                dva1++;
            if (d == 3)
                tri1++;
            if (d == 4)
                cetiri1++;
            if (d == 5)
                pet1++;
            if (d == 6)
                shest1++;
            if (d == 7)
                sedum1++;
            if (d == 8)
                osum1++;
            if (d == 9)
                devet1++;
            v[i].second /= 10;
        }
        if (eden == eden1 and dva == dva1 and tri == tri1 and cetiri == cetiri1 and pet == pet1 and shest == shest1 and sedum == sedum1 and osum == osum1 and devet == devet1)
            rez++;
    }
    cout << rez;
    return 0;
}