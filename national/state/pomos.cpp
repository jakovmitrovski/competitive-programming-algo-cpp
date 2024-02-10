#include <iostream>
#include <string>
using namespace std;

long long solve(int a, int b, int w, int q)
{
    int curr = 0;
    if (b / 2 >= a and q < ((b + 1) / 2) * w)
    {
        if (b % 2 == 0)
        {
            curr += q;
            curr += solve(a, b / 2, w, q);
        }
        else if (b % 2 != 0)
        {
            curr += q;
            curr += solve(a, b / 2, w, q);
        }
    }

    else
        curr += (w * (b - a));

    return curr;
}
int main()
{
    int n, k;

    cin >> n >> k;

    int g;

    cin >> g;

    string c[g];

    int x[g], y[g];

    for (int i = 0; i < g; i++)
        cin >> c[i] >> x[i] >> y[i];

    int m = 0, idx, Min = 2000000000;

    for (int i = 0; i < g; i++)
    {
        m = solve(k, n, x[i], y[i]);

        if (m < Min)
        {
            Min = m;

            idx = i;
        }
    }
    cout << c[idx] << " " << Min << endl;
    return 0;
}