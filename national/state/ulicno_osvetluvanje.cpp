#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, k;

    cin >> n >> k;

    int a[n + 2];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int left = 0, right = 0;
    int fixed = 0;

    int largest_left = 0;
    int largest_right = 0;

    int longest = 0;

    while (right < n)
    {

        if (a[right] == 0)
        {
            if (fixed < k)
            {
                if (longest < right - left + 1)
                {
                    longest = right - left + 1;
                    largest_left = left;
                    largest_right = right;
                }
                right++;
                fixed++;
            }
            else
            {
                if (a[left] == 0)
                    fixed--;

                left++;
            }
        }
        else
        {
            if (longest < right - left + 1)
            {
                longest = right - left + 1;
                largest_left = left;
                largest_right = right;
            }
            right++;
        }

        // cout << left << " " << right << " " << fixed << endl;
    }

    // cout << largest_left << " " << largest_right << endl;

    cout << largest_right - largest_left + 1 << endl;

    for (int i = largest_left; i <= largest_right; i++)
        if (a[i] == 0)
            cout << i + 1 << " ";

    return 0;
}