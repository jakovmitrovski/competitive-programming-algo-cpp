#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int niza[5];
    for (int i = 0; i < 5; i++)
        cin >> niza[i];
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 100;
        return 0;
    }
    int br = 0;
    if (n == 2)
    {
        br = niza[0];
        if (br == 0)
        {
            cout << 100;
            return 0;
        }
        if (br >= 1 and br <= 5)
        {
            cout << 80;
            return 0;
        }
        if (br >= 6 and br <= 20)
        {
            cout << 60;
            return 0;
        }
        if (br > 20)
        {
            cout << 50;
            return 0;
        }
    }
    if (n == 3)
    {
        br = niza[0] + niza[1];
        if (br == 0)
        {
            cout << 100;
            return 0;
        }
        if (br >= 1 and br <= 5)
        {
            cout << 80;
            return 0;
        }
        if (br >= 6 and br <= 20)
        {
            cout << 60;
            return 0;
        }
        if (br > 20)
        {
            cout << 50;
            return 0;
        }
    }
    if (n == 4)
    {
        br = niza[0] + niza[1] + niza[2];
        if (br == 0)
        {
            cout << 100;
            return 0;
        }
        if (br >= 1 and br <= 5)
        {
            cout << 80;
            return 0;
        }
        if (br >= 6 and br <= 20)
        {
            cout << 60;
            return 0;
        }
        if (br > 20)
        {
            cout << 50;
            return 0;
        }
    }
    if (n == 5)
    {
        br = niza[0] + niza[1] + niza[2] + niza[3];
        if (br == 0)
        {
            cout << 100;
            return 0;
        }
        if (br >= 1 and br <= 5)
        {
            cout << 80;
            return 0;
        }
        if (br >= 6 and br <= 20)
        {
            cout << 60;
            return 0;
        }
        if (br > 20)
        {
            cout << 50;
            return 0;
        }
    }
    return 0;
}