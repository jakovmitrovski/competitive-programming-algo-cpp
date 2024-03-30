#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;

    cin >> s;

    string p = s;

    reverse(p.begin(), p.end());

    cout << max(s, p);

    return 0;
}