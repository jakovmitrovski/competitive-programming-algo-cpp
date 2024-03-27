#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cifri[] = {0, 1, 2, 5, 8};

vector<int> limit1, limit2, number;

bool test(vector<int> &v)
{

    for (int i = 0; i < limit1.size(); i++)
        if (limit1[i] > v[i])
            return false;
        else if (limit1[i] < v[i])
            break;

    for (int i = 0; i < limit2.size(); i++)
        if (limit2[i] > v[i])
            break;
        else if (limit2[i] < v[i])
            return false;
    return true;
}

int mirror(vector<int> v)
{
    int result = 0;
    if (limit1.size() % 2 == 1)
    {
        int num = 1;
        v.push_back(0);
        for (int i = v.size() - 2; i >= 0; i--)
        {
            num++;
            if (v[i] == 5)
                v.push_back(2);
            else if (v[i] == 2)
                v.push_back(5);
            else
                v.push_back(v[i]);
        }
        if (test(v))
            result++;
        while (num--)
            v.pop_back();
        num = 1;
        v.push_back(1);
        for (int i = v.size() - 2; i >= 0; i--)
        {
            num++;
            if (v[i] == 5)
                v.push_back(2);
            else if (v[i] == 2)
                v.push_back(5);
            else
                v.push_back(v[i]);
        }
        if (test(v))
            result++;
        while (num--)
            v.pop_back();
        num = 1;
        v.push_back(8);
        for (int i = v.size() - 2; i >= 0; i--)
        {
            num++;
            if (v[i] == 5)
                v.push_back(2);
            else if (v[i] == 2)
                v.push_back(5);
            else
                v.push_back(v[i]);
        }
        if (test(v))
            result++;
        return result;
    }
    else
    {
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i] == 5)
                v.push_back(2);
            else if (v[i] == 2)
                v.push_back(5);
            else
                v.push_back(v[i]);
        }
        if (test(v))
            return 1;
        else
            return 0;
    }
}

int broj_na_palindromi(int n)
{
    int result = 0;
    if (n == 0)
    {
        result += mirror(number);
    }
    else
    {
        int start;

        if (number.empty())
            start = 1;
        else
            start = 0;

        for (; start < 5; start++)
        {
            number.push_back(cifri[start]);
            result += broj_na_palindromi(n - 1);
            number.pop_back();
        }
    }
    return result;
}

int brojNaCifri(long long n)
{
    if (n == 0)
        return 1;
    int rez = 0;
    while (n > 0)
    {
        rez++;
        n /= 10;
    }
    return rez;
}

int main()
{
    long long a, b;
    long long dp[19];
    long long result = 0;

    cin >> a >> b;

    dp[2] = 4;
    for (int i = 3; i < 19; i++)
        if (i % 2 == 0)
            dp[i] = dp[i - 2] * 5;
        else
            dp[i] = dp[i - 1] * 3;

    int cifria, cifrib;
    cifria = brojNaCifri(a);
    cifrib = brojNaCifri(b);

    for (int i = cifria + 1; i < cifrib; i++)
        result += dp[i];

    if (cifria != cifrib)
    {
        while (cifria--)
        {
            limit1.push_back(a % 10);
            limit2.push_back(9);
            a /= 10;
        }
        reverse(limit1.begin(), limit1.end());
        result += broj_na_palindromi(limit1.size() / 2);
        limit1.clear();
        limit2.clear();
        limit1.push_back(1);
        while (cifrib--)
        {
            limit1.push_back(0);
            limit2.push_back(b % 10);
            b /= 10;
        }
        limit1.pop_back();
        reverse(limit2.begin(), limit2.end());
        result += broj_na_palindromi(limit2.size() / 2);
    }

    else
    {
        while (cifria--)
        {
            limit1.push_back(a % 10);
            limit2.push_back(b % 10);
            a /= 10;
            b /= 10;
        }
        reverse(limit1.begin(), limit1.end());
        reverse(limit2.begin(), limit2.end());
        result += broj_na_palindromi(cifrib / 2);
    }

    cout << result;
    return 0;
}
