#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    int n, a;
    cin >> n >> a;
    int left = 0, right = a;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x < left && y > right)
            continue;
        if (x >= left && y <= right)
            res++;
        if (x <= left && y >= left && y <= right && abs(x - left) <= abs(y - left))
        {
            res++;
            left = min(x, left);
        }
        if (x >= left && x <= right && y >= right && abs(right - x) >= abs(right - y))
        {
            res++;
            right = max(y, right);
        }
    }

    cout << res << endl;

    return 0;
}