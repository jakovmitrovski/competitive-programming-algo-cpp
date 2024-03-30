#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int niza[n + 2], dp[n + 2] = {0};

    cin >> niza[0];
    dp[0] = niza[0];
    for (int i = 1; i < n; i++)
    {
        cin >> niza[i];
        dp[i] = dp[i - 1] + niza[i];
    }

    double avg[n + 2] = {0.0};
    int rez = 0;
    double najgolem = dp[n - 1] / (n * 1.0);
    for (int i = 0; i < n - 1; i++)
    {
        avg[i] = (dp[n - 1] - dp[i]) / ((n - 1 - i) * 1.0);
        if (avg[i] > najgolem)
        {
            najgolem = avg[i];
            rez = i + 1;
        }
    }

    cout << rez;

    return 0;
}