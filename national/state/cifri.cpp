#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;
int k;
string rez = "0";

void rek(int n, string mom, int zemeni)
{
    if (zemeni == s.size() - k)
    {
        reverse(mom.begin(), mom.end());
        rez = max(rez, mom);
    }
    else
    {
        if (n < 0)
            return;

        rek(n - 1, mom + s[n], zemeni + 1);
        rek(n - 1, mom, zemeni);
    }
}

int main()
{

    cin >> s >> k;
    rek(s.size() - 1, "", 0);
    cout << rez;
    return 0;
}