#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int rez = 0;
    for (int i = 0; i < n; i += k)
        rez += 2 * v[i];

    cout << rez;
    return 0;
}