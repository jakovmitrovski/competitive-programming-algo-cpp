#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int niza[10], br = 0;
    vector<int> v;
    for (int i = 0; i < 10; i++)
        cin >> niza[i];
    for (int i = 0; i < 10; i++)
    {
        int c = niza[i] % 42;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        br++;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] == v[j])
                br--;
            if (v[i] == v[j] and v[j] == v[j + 1])
                br++;
        }
    }
    cout << endl;
    cout << br;
    return 0;
}