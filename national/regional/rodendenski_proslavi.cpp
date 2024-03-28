#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
    int n, den, mesec, sum[15] = {0};
    cin >> n;

    bool data[20][50] = {false};

    for (int i = 0; i < n; i++)
    {
        cin >> den >> mesec;

        if (data[mesec][den] == false)
        {
            data[mesec][den] = true;
            sum[mesec]++;
        }
    }

    int najgolem = 0;

    for (int i = 0; i <= 12; i++)
    {
        if (sum[i] > najgolem)
            najgolem = sum[i];
    }

    for (int i = 0; i <= 12; i++)
    {
        if (sum[i] == najgolem)
            v.push_back(i);
    }

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    return 0;
}