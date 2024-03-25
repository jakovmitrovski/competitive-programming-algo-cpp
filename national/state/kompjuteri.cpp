#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long s, n;
    cin >> s >> n;

    long long cnt = 0;

    while (n > s)
    {
        long long next;
        if (n % 2 == 0)
        {
            if (n / 2 >= s)
            {
                next = n / 2L;
            }
            else if (n - 2 >= s)
            {
                next = n - 2;
            }
            else
            {
                next = n - 1;
            }
        }
        else
        {
            if (n / 2 >= s)
            {
                next = n - 1;
            }
            else if (n - 2 >= s)
            {
                next = n - 2;
            }
            else
            {
                next = n - 1;
            }
        }

        if (next == s)
        {
            cout << cnt + 1;
            return 0;
        }
        cnt++;
        // cout << n << " " << next << endl;
        n = next;
    }

    return 0;
}
