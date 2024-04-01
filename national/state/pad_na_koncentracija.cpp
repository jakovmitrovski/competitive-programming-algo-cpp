#include <bits/stdc++.h>

using namespace std;

int main()
{

    int m, n;

    cin >> m >> n;

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (i >= m)
            cnt += i % 3 + 1;
    }

    cout << cnt << endl;

    return 0;
}