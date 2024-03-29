#include <bits/stdc++.h>

using namespace std;

vector<set<int>> v(21);
vector<set<int>> v1(21);
int parent[21];
vector<int> red;
bool visited[21];
vector<set<int>> sccGraph(21);

void dfs(int node)
{
    visited[node] = true;

    for (auto next : v[node])
    {
        if (!visited[next])
        {
            dfs(next);
        }
    }

    red.push_back(node);
}

void dfs2(int node, int start)
{
    visited[node] = true;
    // cout << node << " ";
    parent[node] = start;
    for (auto next : v1[node])
        if (!visited[next])
            dfs2(next, start);
}

int main()
{

    int n, k;
    cin >> n >> k;

    bool hasSelf[n + 2];
    memset(hasSelf, false, sizeof hasSelf);
    memset(visited, false, sizeof visited);

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a != b)
        {
            v[a].insert(b);
            v1[b].insert(a);
        }
        else
        {
            hasSelf[a] = true;
        }
    }

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    reverse(red.begin(), red.end());

    memset(visited, false, sizeof visited);

    for (auto node : red)
        if (!visited[node])
        {
            // cout << "in component are: ";
            dfs2(node, node);
            // cout << endl;
        }

    set<int> components;
    vector<int> sizes(n, 0);

    for (int i = 0; i < n; i++)
    {
        components.insert(parent[i]);
        sizes[parent[i]]++;
    }

    for (int i = 0; i < n; i++)
        for (auto node : v[i])
        {
            if (parent[i] != parent[node])
            {
                sccGraph[parent[i]].insert(parent[node]);
            }
        }

    bool allInSCC = true;

    for (auto component : components)
    {
        if (sizes[component] == 1)
        {
            allInSCC = false;
            break;
        }
    }

    if (allInSCC)
    {
        cout << 0 << endl;
        return 0;
    }

    int id[n + 2];
    memset(id, -1, sizeof id);

    int tmp = 0;

    for (auto x : components)
    {
        // cout << x << endl;
        id[x] = tmp++;
    }

    unsigned long C = components.size();

    unsigned long ans = 1 << 20;

    for (int mask = 0; mask < (1 << C); mask++)
    {

        if (__builtin_popcount(mask) == 1)
            continue;

        int in[n + 2];
        int out[n + 2];

        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);

        for (auto component : components)
        {
            for (auto node : sccGraph[component])
            {
                if ((mask & (1 << id[component])) > 0 && (mask & (1 << id[node])) > 0)
                {
                    in[node]++;
                    out[component]++;
                }
            }
        }

        int total_in = 0;
        int total_out = 0;

        for (auto component : components)
        {
            //            cout << component << " " << in[component] << " " << out[component] << endl;
            //            cout << "before " << total_in << " " << total_out << endl;
            if (in[component])
                total_in++;
            if (out[component])
                total_out++;
            //            cout << "after " << total_in << " " << total_out << endl;
        }

        unsigned long addSelfEdge = 0;

        for (auto component : components)
        {
            if (sizes[component] == 1 && !hasSelf[component] && (mask & (1 << id[component])) == 0)
                addSelfEdge++;
        }

        //         cout << bitset<4>(mask).to_string() << " " << max(__builtin_popcount(mask) - total_in, __builtin_popcount(mask) - total_out) + addSelfEdge << " " << __builtin_popcount(mask) << " " << total_in << " " << total_out << " " << addSelfEdge << endl;

        ans = min(ans, max(__builtin_popcount(mask) - total_in, __builtin_popcount(mask) - total_out) + addSelfEdge);

        //        cout << "components" << endl;
        //
        //        for (auto component: components) {
        //            cout << component << " ";
        //        }
        //        cout << endl;
        //
        //        cout << "result for " << bitset<3>(mask).to_string() << " " << ans << " " << components.size() << " " << total_in << " " << total_out << " " << toAdd << " " << endl;
    }

    cout << ans << endl;

    return 0;
}