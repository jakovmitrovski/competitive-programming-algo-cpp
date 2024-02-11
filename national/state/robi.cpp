#include <bits/stdc++.h>

using namespace std;

map<int, int> level_to_number;

void syspause()
{
    do
    {
        cout << '\n'
             << "Press the Enter key to continue.";
    } while (cin.get() != '\n');
}

vector<pair<int, int>> intersections;

vector<pair<int, int>> f(int r, int c)
{
    vector<pair<int, pair<int, int>>> tmp;
    for (auto p : intersections)
    {
        tmp.emplace_back(abs(r - p.first) + abs(c - p.second), p);
    }

    int confusing = 1;
    sort(tmp.begin(), tmp.end());
    while (confusing < intersections.size() && tmp[confusing].first == tmp[0].first)
        confusing++;

    vector<pair<int, int>> ret;
    for (int j = 0; j < confusing; j++)
    {
        ret.emplace_back(tmp[j].second);
    }
    return ret;
}

int solve(int rx, int cx, int ry, int cy)
{

    if (rx > ry)
        return 0;
    if (cx > cy)
        return 0;

    vector<pair<int, int>> fi = f(rx, cx);

    if (fi == f(rx, cy) && fi == f(ry, cx) && fi == f(ry, cy))
    {

        if (fi.size() == 1)
        {
            return 0;
        }
        else
        {
            return (ry - rx + 1) * (cy - cx + 1);
        }
    }
    else
    {
        int r = (rx + ry) / 2;
        int c = (cx + cy) / 2;
        int ret = solve(rx, cx, r, c);
        ret += solve(rx, c + 1, r, cy);
        ret += solve(r + 1, cx, ry, c);
        ret += solve(r + 1, c + 1, ry, cy);
        return ret;
    }
}

int main()
{

    int v, h, n;

    cin >> v >> h >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        intersections.emplace_back(a, b);
    }

    cout << solve(1, 1, v, h);

    return 0;
}