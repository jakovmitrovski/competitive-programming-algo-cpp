#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int c, d;
        cin >> c >> d;
        pair<int, int> par;
        par.first = c;
        par.second = d;
        v.push_back(par);
    }

    int rez = 0;

    vector<pair<int, int>> r;

    for (int i = 0; i < n; i++)
    {
        if (v[i].first <= a and v[i].second <= b)
        {
            rez++;
            pair<int, int> par1;
            par1.first = v[i].first;
            par1.second = v[i].second;

            r.push_back(par1);
        }
        else
        {
            swap(v[i].first, v[i].second);

            if (v[i].first <= a and v[i].second <= b)
            {
                rez++;
                pair<int, int> par1;
                par1.first = v[i].second;
                par1.second = v[i].first;

                r.push_back(par1);
            }
        }
    }

    cout << rez << endl;

    for (int i = 0; i < r.size(); i++)
        cout << r[i].first << " " << r[i].second << endl;

    return 0;
}