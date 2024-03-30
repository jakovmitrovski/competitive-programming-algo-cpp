#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string a, string b)
{
    int digits = max(a.size(), b.size());
    string result(digits, '0');

    int carry = 0;
    int posA = a.size() - 1;
    int posB = b.size() - 1;
    int posResult = max(a.size(), b.size()) - 1;

    while (posA >= 0 || posB >= 0)
    {
        int digitA = (posA >= 0) ? (a[posA] - '0') : 0;
        int digitB = (posB >= 0) ? (b[posB] - '0') : 0;

        int sum = (digitA + digitB + carry);

        result[posResult] = (char)((sum % 10) + '0');
        carry = (sum / 10);

        posA--;
        posB--;
        posResult--;
    }

    if (carry > 0)
    {
        result = "1" + result;
    }

    return result;
}

int main()
{
    int N;
    cin >> N;

    string result = "0";
    string power = "1";
    for (int i = 1; i <= N; i++)
    {

        power = add(power, power);
        result = add(result, power);
    }

    cout << result << endl;
    return 0;
}