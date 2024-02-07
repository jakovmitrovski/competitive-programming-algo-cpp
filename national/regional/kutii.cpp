#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p;
    vector<int> ku;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        p.push_back(a);
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < k; i++)
    {
        int b;
        cin >> b;
        ku.push_back(b);
    }

    sort(ku.begin(), ku.end());

    bool izbrana[10000] = {false};
    bool izbrana2[1000] = {false};

    int rez = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            if (p[i] <= ku[j] and izbrana[j] == false and izbrana2[i] == false)
            {
                rez++;
                izbrana[j] = true;
                izbrana[i] = true;
                break;
            }
    }

    cout << rez;
    return 0;
}