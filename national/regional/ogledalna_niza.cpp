#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int operations = 0, left = 0, right = n - 1;

    while (left <= right)
    {
        if (a[left] == a[right])
        {
            left++;
            right--;
        }
        else if (a[left] < a[right])
        {
            a[left + 1] += a[left];
            left++;
            operations++;
        }
        else
        {
            a[right - 1] += a[right];
            right--;
            operations++;
        }
    }

    cout << operations << endl;

    return 0;
}