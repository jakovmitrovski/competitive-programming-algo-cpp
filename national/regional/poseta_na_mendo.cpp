#include <bits/stdc++.h>

using namespace std;

int k, n;
int a[int(1e6) + 7], b[int(1e6) + 7];
int sufa[int(1e6) + 7], sufb[int(1e6) + 7];

int main()
{

    cin >> k >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);
    reverse(b, b + n);

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {

        int lo = 0, hi = n;
        int best = 0;
        while (lo < hi)
        {
            int mid = lo + hi >> 1;
            if (a[i] + b[mid] >= k)
            {
                lo = mid + 1;
                best = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        ans += best;
    }

    cout << ans << endl;

    return 0;
}