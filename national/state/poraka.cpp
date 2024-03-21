#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    string P;
    cin >> P;

    int changes = 0;

    for (int j = 0; j < K; ++j)
    {
        vector<int> count(26, 0);
        for (int i = j; i < N; i += K)
        {
            count[P[i] - 'A']++;
        }

        int maxCount = *max_element(count.begin(), count.end());
        changes += (N / K) - maxCount;
    }

    cout << changes << endl;

    return 0;
}
