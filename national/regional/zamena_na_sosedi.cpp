#include <iostream>

using namespace std;

int segTree[300003], niza[100001], pojavuvanja[100001];

void build(int l, int r, int p)
{
    if (l == r)
    {
        segTree[p] = pojavuvanja[l];
    }
    else
    {
        build(l, (l + r) / 2, 2 * p);
        build((l + r) / 2 + 1, r, 2 * p + 1);
        segTree[p] = segTree[2 * p] + segTree[2 * p + 1];
    }
}

int query(int i, int j, int l, int r, int p)
{
    if (i > r || j < l)
        return 0;
    if (i <= l && j >= r)
        return segTree[p];
    return query(i, j, l, (r + l) / 2, 2 * p) + query(i, j, (r + l) / 2 + 1, r, 2 * p + 1);
}

void update(int index, int value, int l, int r, int p)
{
    if (l == r)
    {
        pojavuvanja[l] = segTree[p] = value;
    }
    else
    {
        if (index > (l + r) / 2)
            update(index, value, (r + l) / 2 + 1, r, 2 * p + 1);

        else
            update(index, value, l, (r + l) / 2, 2 * p);

        segTree[p] = segTree[2 * p] + segTree[2 * p + 1];
    }
}

int main()
{
    int n;
    long long rez = 0;
    cin >> n;
    build(1, n, 1);
    for (int i = 0; i <= n; i++)
        pojavuvanja[i] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> niza[i];
        update(niza[i], pojavuvanja[niza[i]] + 1, 1, n, 1);
        rez += query(niza[i] + 1, n, 1, n, 1);
    }
    cout << rez;
    return 0;
}