#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, niz[100002];
vector<int> a, t;

void update(int x)
{
    for (int i = x; i <= 100000; i += i & -i)
        niz[i]++;
}
int query(int x)
{
    long long sum = 0;
    for (int i = x; i > 0; i -= i & -i)
        sum += niz[i];
    return sum;
}

int main()
{
    int i, j, r;
    memset(niz, 0, sizeof(niz));
    long long ans = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> r;
        a.push_back(r);
    }

    t = a;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    for (i = 0; i < n; i++)
        a[i] = lower_bound(t.begin(), t.end(), a[i]) - t.begin();
    int rez1[100001], rez2[100001];
    for (i = 0; i < a.size(); i++)
    {
        a[i]++;
        update(a[i]);
        rez1[i] = query(100000) - query(a[i]);
    }
    memset(niz, 0, sizeof(niz));
    for (i = a.size() - 1; i >= 0; i--)
    {
        update(a[i]);
        rez2[i] = query(a[i] - 1);
    }
    for (i = 0; i < a.size(); i++)
        ans += rez1[i] * rez2[i];
    cout << ans << endl;
    return 0;
}