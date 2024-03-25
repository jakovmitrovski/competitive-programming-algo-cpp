#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long n;
    cin >> n;

    long long a[n + 2];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    long long ans = 0;

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            ans = max(ans, (j - i) * a[i] + (n - j) * a[j]);

    cout << ans;

    return 0;
}