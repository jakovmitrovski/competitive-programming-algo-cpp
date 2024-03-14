#include <iostream>

using namespace std;

int main()
{
    string s;
    int zbir = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        zbir += s[i] - 48;
    if (zbir % 9 == 0)
        cout << 0;
    else if (zbir % 3 == 0)
        cout << 2;
    else
        cout << 8;
}