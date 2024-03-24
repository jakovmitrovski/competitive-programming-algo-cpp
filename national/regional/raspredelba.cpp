#include <bits/stdc++.h>

using namespace std;

map<vector<int>, int> steps, steps_b;

int main()
{

    int n;
    cin >> n;

    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        a.push_back(c);
    }

    int m;
    cin >> m;
    vector<int> b;
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        b.push_back(c);
    }

    bool flag = true;
    for (int i = 0; i < n && flag; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                a.erase(a.begin() + i, a.begin() + i + 1);
                b.erase(b.begin() + j, b.begin() + j + 1);
                n--, m--;
                if (i >= n || j >= m)
                {
                    flag = false;
                    break;
                }
            }
        }

    queue<vector<int>> q;

    vector<vector<int>> states, states_b;

    sort(a.begin(), a.end());

    q.push(a);

    while (!q.empty())
    {
        auto x = q.front();
        q.pop();

        //        for (auto t : x ) cout << t << " ";
        //        cout << endl;

        states.push_back(x);

        if (x.size() == 1)
            continue;
        for (int i = 0; i < x.size(); i++)
            for (int j = i + 1; j < x.size(); j++)
            {
                vector<int> curr = x;
                curr.erase(curr.begin() + i, curr.begin() + i + 1);
                curr.erase(curr.begin() + j - 1, curr.begin() + j);
                curr.push_back(x[i] + x[j]);
                sort(curr.begin(), curr.end());
                if (steps[curr] == 0)
                {
                    steps[curr] = steps[x] + 1;
                    q.push(curr);
                }
            }
    }

    sort(b.begin(), b.end());
    q.push(b);

    while (!q.empty())
    {
        auto x = q.front();
        q.pop();

        //        for (auto t : x) cout << t << " ";
        //        cout << endl;

        states_b.push_back(x);

        if (x.size() == 1)
            continue;
        for (int i = 0; i < x.size(); i++)
            for (int j = i + 1; j < x.size(); j++)
            {
                vector<int> curr = x;
                curr.erase(curr.begin() + i, curr.begin() + i + 1);
                curr.erase(curr.begin() + j - 1, curr.begin() + j);
                curr.push_back(x[i] + x[j]);
                sort(curr.begin(), curr.end());
                if (steps_b[curr] == 0)
                {
                    steps_b[curr] = steps_b[x] + 1;
                    q.push(curr);
                }
            }
    }

    int ans = 1 << 25;

    for (auto x : states)
        if ((steps[x] != 0 || x == a) && (steps_b[x] != 0 || x == b))
            ans = min(ans, steps[x] + steps_b[x]);
    for (auto x : states_b)
        if ((steps[x] != 0 || x == a) && (steps_b[x] != 0 || x == b))
            ans = min(ans, steps[x] + steps_b[x]);

    if (ans == (1 << 25))
        ans = -1;
    cout << ans;

    return 0;
}