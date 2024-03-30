#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> cords_DD;
vector<int> cords_LL;
vector<pair<char, char>> shoes;
void find_cords()
{
    for (int i = 0; i < shoes.size(); i++)
    {
        pair<char, char> at = shoes[i];
        if (at.first == 'D' && at.second == 'D')
            cords_DD.push_back(i);
        else if (at.first == 'L' && at.second == 'L')
            cords_LL.push_back(i);
        else
            continue;
    }
    return;
}
long long count_changes()
{
    long long changes = 0;
    if ((cords_DD.size() > cords_LL.size()) || cords_LL.size() > cords_DD.size())
        return -1;

    else
    {
        for (int i = 0; i < cords_DD.size(); i++)
        {
            int DD_c = cords_DD[i], LL_c = cords_LL[i], raz;

            if (DD_c > LL_c)
                raz = DD_c - LL_c;

            else if (LL_c > DD_c)
                raz = LL_c - DD_c;

            else
                raz = 0;

            changes += raz;
        }
    }
    return changes;
}
int main()
{
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        shoes.push_back(make_pair(a[0], a[1]));
    }
    find_cords();
    long long changes = count_changes();
    cout << changes << endl;
    return 0;
}