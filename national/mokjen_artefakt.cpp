#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 2];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum <= n) cnt++;
    }
    cout << cnt;
    return 0;
}