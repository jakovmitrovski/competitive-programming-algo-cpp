#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> taken;
bool sort_by_the_end_time(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void activities(vector<pair<int, int>> a, int time_start)
{
    int last = 0;
    taken.push_back(last);

    for (int i = 1; i < a.size(); i++)
    {
        if (a[i].first >= a[last].second)
        {
            taken.push_back(i);
            last = i;
        }
    }

    for (int i = 1; i < taken.size(); i++)
    {
        int t = taken[i];

        int start = a[taken[i - 1]].second, end = time_start + 24 * 60;
        if (i != taken.size() - 1)
            end = a[taken[i + 1]].first;

        for (int j = 0; j < a.size(); j++)
            if (a[j].second - a[j].first > a[t].second - a[t].first)
                if (a[j].first >= start && a[j].second <= end)
                {
                    taken[i] = j;
                    break;
                }
    }
}

int solve(vector<pair<int, int>> a, int f)
{
    vector<pair<int, int>> shows;
    shows.push_back(a[f]);

    int time_start = a[f].first;
    int time_end = time_start + 24 * 60;

    for (int i = 0; i < a.size(); i++)
    {
        if (i != f)
        {
            pair<int, int> show = a[i];

            while (show.first < shows[0].second)
            {
                show.first += (24 * 60);
                show.second += (24 * 60);
            }

            if (show.second <= time_end)
                shows.push_back(show);
        }
    }

    sort(a.begin(), a.end(), sort_by_the_end_time);

    taken.clear();
    activities(shows, time_start);

    int result = 0;
    for (int i = 0; i < taken.size(); i++)
    {
        pair<int, int> show = shows[taken[i]];
        result += (show.second - show.first);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        int sh, sm, eh, em;
        cin >> sh >> sm >> eh >> em;

        a[i].first = sh * 60 + sm;
        a[i].second = eh * 60 + em;

        if (a[i].second <= a[i].first)
            a[i].second += (24 * 60);
    }

    int best = 0;
    for (int i = 0; i < n; i++)
    {
        int minutes = solve(a, i);
        best = max(best, minutes);
    }

    cout << best << endl;
    return 0;
}