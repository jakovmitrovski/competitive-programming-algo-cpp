#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int niza[n + 2];

    for (int i = 0; i < n; i++)
        cin >> niza[i];

    int zbir = 0;

    for (int i = 0; i < n; i++)
        zbir += niza[i];

    int dp[110000] = {0};

    dp[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = zbir; j >= 0; j--)

            if (dp[j] == 1)
                dp[j + niza[i]] = 1;

    int razlika = 0;

    for (int i = zbir / 2; i >= 0; i--)
        if (dp[i] == 1)
        {
            razlika = zbir - i;

            if (razlika - i > 0 or razlika - i == 0)
            {
                cout << razlika - i;
            }
            else if (razlika - i < 0)
            {
                cout << -(razlika - i);
            }

            break;
        }

    return 0;
}