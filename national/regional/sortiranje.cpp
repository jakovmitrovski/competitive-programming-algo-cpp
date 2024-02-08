#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<double, pair<int, string>>> v;

int main()
{
    int n;

    cin >> n;

    string niza[n + 2];

    for (int i = 0; i < n; i++)
        cin >> niza[i];

    for (int i = 0; i < n; i++)
    {
        double sum = 0.0, avg = 0.0;

        string s = niza[i];

        for (int j = 0; j < s.size(); j++)
        {
            double c = s[j] - 'A' + 1.0;

            sum += c;
        }
        avg = sum / (s.size() * 1.0);
        pair<double, pair<int, string>> par;

        par.first = avg;
        par.second = make_pair(i, niza[i]);

        v.push_back(par);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
        cout << v[i].second.second << " " << endl;

    return 0;
}