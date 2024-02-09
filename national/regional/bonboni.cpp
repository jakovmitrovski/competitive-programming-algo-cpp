#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nino;
    vector<int> tino;
    int c = 1;

    nino.push_back(n);

    while (n > 0)
    {
        if (n % 3 == 0)
        {
            n /= 3;
            c *= 3;
            continue;
        }

        if (n % 3 == 1)
        {
            n -= 1;
            n /= 3;
            tino.push_back(c);
            c *= 3;
            continue;
        }

        if (n % 3 == 2)
        {
            n += 1;
            n /= 3;
            nino.push_back(c);
            c *= 3;
            continue;
        }
    }

    sort(nino.begin(), nino.end());
    sort(tino.begin(), tino.end());

    for (int i = 0; i < nino.size(); i++)
        cout << nino[i] << " ";

    cout << endl;

    for (int i = 0; i < tino.size(); i++)
        cout << tino[i] << " ";

    return 0;
}