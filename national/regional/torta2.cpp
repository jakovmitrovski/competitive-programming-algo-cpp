#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int length(int num)
{
    int digits = 1;

    while (num >= 10)
    {
        num /= 10;
        digits++;
    }

    return digits;
}

int solve(int n)
{
    int plen = 0, end = 0;

    for (int i = 1;; i++)
    {
        plen += length(i);

        if (n > plen)
        {
            n -= plen;
        }
        else
        {
            end = i;
            break;
        }
    }

    ostringstream oss;

    for (int j = 1; j <= end; j++)
        oss << j;

    string res = oss.str();
    return ((int)(res[n - 1] - '0'));
}

int main()
{
    int n;
    cin >> n;

    cout << solve(n) << endl;
    return 0;
}