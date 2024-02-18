#include <iostream>
using namespace std;
int maximalen(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
                swap(a[i], a[j]);
        }
    }
    return a[0];
}
int main()
{
    int n;
    cin >> n;
    int a[n + 2];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int c = maximalen(a, n);
    int br = 0;
    for (int i = 0; i < n; i++)
    {
        int b = 0;
        if (a[i] < c)
        {
            b = c - a[i];
            br += b;
        }
        else
            continue;
    }
    cout << br;
    return 0;
}