#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v(100002);

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;

        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    bool visited[n + 2];

    memset(visited, false, sizeof(visited));

    vector<int> v1;

    v1.push_back(0);

    visited[0] = true;

    visited[n] = true;

    queue<int> q;

    q.push(0);

    while (!q.empty())
    {
        int teme = q.front();

        q.pop();

        for (int i = 0; i < v[teme].size(); i++)
        {
            if (visited[v[teme][i]] == false)
            {
                visited[v[teme][i]] = true;

                v1.push_back(v[teme][i]);

                q.push(v[teme][i]);
            }
        }
    }

    q.push(n);

    vector<int> v2;

    v2.push_back(n);

    while (!q.empty())
    {
        int teme = q.front();

        q.pop();

        for (int i = 0; i < v[teme].size(); i++)
            if (visited[v[teme][i]] == false)
            {
                visited[v[teme][i]] = true;

                v2.push_back(v[teme][i]);

                q.push(v[teme][i]);
            }
    }

    reverse(v2.begin(), v2.end());

    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";

    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";

    return 0;
}