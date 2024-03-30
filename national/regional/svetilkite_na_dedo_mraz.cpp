#include <bits/stdc++.h>

using namespace std;

int st[400001];
int arr[100001];
int n;
int lazy[400001];

void build(int idx = 1, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        st[idx] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);

    st[idx] = st[2 * idx] + st[2 * idx + 1];
}

void update(int x, int y, int val, int idx = 1, int l = 0, int r = n - 1)
{
    if (lazy[idx] != -1)
    {
        st[idx] = (r - l + 1) * lazy[idx];
        if (l != r)
        {
            lazy[2 * idx] = lazy[idx];
            lazy[2 * idx + 1] = lazy[idx];
        }
        lazy[idx] = -1;
    }

    if (l > y || r < x)
        return;

    if (l >= x && r <= y)
    {
        st[idx] = (r - l + 1) * val;
        if (l != r)
        {
            lazy[2 * idx] = val;
            lazy[2 * idx + 1] = val;
        }
        return;
    }

    int mid = (l + r) / 2;

    update(x, y, val, 2 * idx, l, mid);
    update(x, y, val, 2 * idx + 1, mid + 1, r);

    st[idx] = st[2 * idx] + st[2 * idx + 1];
}

int query(int x, int y, int idx = 1, int l = 0, int r = n - 1)
{
    if (lazy[idx] != -1)
    {
        st[idx] = (r - l + 1) * lazy[idx];
        if (l != r)
        {
            lazy[2 * idx] = lazy[idx];
            lazy[2 * idx + 1] = lazy[idx];
        }
        lazy[idx] = -1;
    }

    if (l > y || r < x)
        return 0;

    if (l >= x && r <= y)
        return st[idx];

    int mid = (l + r) / 2;

    return query(x, y, 2 * idx, l, mid) + query(x, y, 2 * idx + 1, mid + 1, r);
}

int main()
{

    int m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    memset(lazy, -1, sizeof lazy);

    build();

    for (int i = 0; i < m; i++)
    {
        char a;
        int x, y;
        cin >> a >> x >> y;
        x--;
        y--;
        if (a == '?')
        {
            cout << query(x, y) << endl;
        }
        else if (a == '+')
        {
            update(x, y, 1);
        }
        else
        {
            update(x, y, 0);
        }
    }

    return 0;
}