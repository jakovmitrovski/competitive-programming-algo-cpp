#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, a, b, r;

    cin >> n >> a >> r >> b;

    int bought = n / a;

    int back = bought * r;

    int bought2 = (n % a + back) / b;

    if (bought2 > bought)
    {
        cout << "DA";
    }
    else
        cout << "NE";

    return 0;
}