#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;

    cin >> n;

    int ans = 0;

    while (n > 0)
    {
        if (n == 1)
            ans += 15;
        else if (n == 2)
            ans += 9;
        else if (n >= 3 && n <= 6)
            ans += 4;
        else
            ans += 5;
        n--;
    }

    cout << ans << endl;

    return 0;
}