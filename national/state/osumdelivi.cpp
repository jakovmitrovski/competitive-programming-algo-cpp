#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MOD = 1000000007;

int main()
{
    int n;

    long long odg = 0;

    cin >> n;

    vector<vector<long long>> vec1(10, vector<long long>(2));
    vector<long long> cifriVec(10);

    long long pow2[200001];
    pow2[0] = 1;
    for (int d = 1; d <= n; d++)
    {
        pow2[d] = (pow2[d - 1] * 2) % MOD;
    }

    string num;
    cin >> num;

    long long lastP = 0;
    long long lastN = 0;

    for (int i = 0; i < num.size(); i++)
    {
        int cifra = num[i] - '0';

        if (cifra % 8 == 0)
        {
            odg++;
        }
        for (int a = 0; a < 10; a++)
        {
            int temp_num = a * 10 + cifra;

            if (temp_num % 8 == 0)
            {

                odg += cifriVec[a];
                odg += vec1[a][0];
            }
            if ((temp_num + 4) % 8 == 0)
            {
                odg += vec1[a][1];
            }

            odg = odg % MOD;
        }
        vec1[cifra][0] = (vec1[cifra][0] + lastP) % MOD;
        vec1[cifra][1] = (vec1[cifra][1] + lastN) % MOD;

        if (cifra % 2 == 0)
        {
            lastP += pow2[i];
        }
        if (cifra % 2 == 1)
        {
            lastN += pow2[i];
        }

        cifriVec[cifra]++;
    }
    odg = odg % MOD;
    cout << odg;

    return 0;
}