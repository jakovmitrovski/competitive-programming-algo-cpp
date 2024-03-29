#include <bits/stdc++.h>

using namespace std;

long long weight[50001];
vector<vector<int>> v(50001);

bool visited[50001];
long long sum[50001];
vector<pair<long long, int>> sums;
int parent[50001];
bool dirty[50001];

long long solve(int node)
{

    if (visited[node])
        return 0;

    if (!dirty[node])
        return sum[node];

    if (v[node].empty())
    {
        sum[node] = weight[node];
        // cout << "WHY AM I NOT HERE " << node << endl;
        sums.emplace_back(sum[node], node);
        dirty[node] = false;
        return weight[node];
    }

    long long ans = weight[node];

    for (int next : v[node])
    {
        ans += solve(next);
    }

    sum[node] = ans;
    sums.emplace_back(sum[node], node);
    dirty[node] = false;
    return ans;
}

void visit(int node)
{
    visited[node] = true;
    if (v[node].empty())
        return;

    for (int next : v[node])
    {
        if (!visited[next])
            visit(next);
    }
}

int main()
{

    int n, k;
    cin >> n >> k;

    v.clear();

    int seen[n + 2];
    for (int i = 0; i < n + 2; i++)
        seen[i] = 2 * n + 2;
    memset(parent, -1, sizeof parent);
    memset(dirty, true, sizeof dirty);

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    seen[0] = true;

    vector<pair<int, int>> input;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        input.emplace_back(a, b);
    }

    sort(input.begin(), input.end());

    int pom = 1;

    for (auto in : input)
    {
        int a = in.first;
        int b = in.second;
        if (seen[a] <= seen[b])
        {
            v[a].push_back(b);
            parent[b] = a;
        }
        else
        {
            v[b].push_back(a);
            parent[a] = b;
        }
        if (seen[a] == 2 * n + 2)
            seen[a] = pom;
        if (seen[b] == 2 * n + 2)
            seen[b] = pom;
        pom++;
    }

    long long ans = solve(0);

    sort(sums.begin(), sums.end());

    memset(visited, false, sizeof visited);

    //    for (int i=0; i<n; i++) {
    //        cout << "deca na " << i << " se: ";
    //        for (auto x: v[i]) cout << x << " ";
    //        cout << endl;
    //    }
    //
    //    long long pp = 0;
    //

    for (int i = 0; i < k; i++)
    {
        long long val = sums[0].first;
        int node = sums[0].second;

        if (val >= 0)
        {
            break;
        }

        // cout << node << endl;

        visit(node);

        while (node != -1)
        {
            dirty[node] = true;
            // cout << node << (dirty[node] ? " true" : " false") << endl;
            node = parent[node];
        }
        //        cout << "BEFORE " << endl;
        //        for (auto x: sums) {
        //            cout << x.first << " " << x.second << endl;
        //        }

        vector<int> indexes;

        for (int j = 0; j < sums.size(); ++j)
        {
            if (visited[sums[j].second] || dirty[sums[j].second])
            {
                // cout << "removes " << sums[j].second << endl;
                indexes.push_back(j);
            }
        }

        sort(indexes.begin(), indexes.end());
        reverse(indexes.begin(), indexes.end());

        for (auto j : indexes)
            sums.erase(sums.begin() + j);

        solve(0);

        sort(sums.begin(), sums.end());

        ans -= val;
    }

    cout << ans << endl;
}
