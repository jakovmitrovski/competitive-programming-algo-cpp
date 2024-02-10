#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    pair<pair<int, int>, pair<int, int>> nizica[100000];
    pair<pair<int, int>, pair<int, int>> par;

    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        par.first.first = a;
        par.first.second = b;
        par.second.first = a + c;
        par.second.second = b + d;
        nizica[i] = par;
    }

    int e, f;
    cin >> e >> f;

    if (n == 1 and f == e / 2)
    {
        cout << "pozadina";
        return 0;
    }

    for (int i = n - 1; i >= 0; i--)
        if (nizica[i].first.first <= e and nizica[i].first.second <= f and nizica[i].second.first >= e and nizica[i].second.second >= f)
        {
            cout << "prozorec " << i + 1;
            return 0;
        }

    cout << "pozadina";

    return 0;
}