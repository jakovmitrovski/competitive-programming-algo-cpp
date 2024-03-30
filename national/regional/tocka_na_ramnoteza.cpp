#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    if (n == 2)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int dp1[n + 2], dp2[n + 2];
    dp1[0] = v[0];

    for (int i = 1; i < n; i++)
        dp1[i] = dp1[i - 1] + v[i];

    dp2[n - 1] = v[n - 1];

    for (int i = n - 2; i >= 0; i--)
        dp2[i] = dp2[i + 1] + v[i];

    for (int i = 1; i < n - 1; i++)
        if (dp1[i - 1] == dp2[i + 1])
        {
            cout << i + 1 << endl;
            return 0;
        }

    cout << -1 << endl;

    return 0;
}
