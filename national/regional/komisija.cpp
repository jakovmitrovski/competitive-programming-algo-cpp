#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int s = 0;
    vector<int> v;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;

        v.push_back(a);

        s += a;
    }

    for (int i = 1; i <= s; i++)
    {
        int people = 1;
        int mom = 0;

        for (int j = 0; j < k; j++)
        {
            if (v[j] > i)
            {
                people = 1 << 20;
                break;
            }

            if (mom + v[j] > i)
            {
                /// ne moze kaj ovoj, mora nov covek
                people++;
                mom = v[j];
            }

            else
                mom += v[j];
        }

        if (people <= n)
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}