#include <bits/stdc++.h>

using namespace std;

int main()
{

    int h, m1, s1;

    cin >> h >> m1 >> s1;

    int m2, s2;

    cin >> m2 >> s2;

    int ans = s2 + 60 * m2 + s1 + 60 * m1 + 3600 * h;

    cout << ans / 3600 << " " << (ans % 3600) / 60 << " " << ans % 60 << endl;

    return 0;
}