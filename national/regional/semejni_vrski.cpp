#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int s, a, b, t;
    cin >> s;
    a = s % 10;
    b = s / 10;
    t = (a * 10) + b;
    cout << s + t;
    return 0;
}