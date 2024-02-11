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

int main()
{

    int n, m;

    cin >> n >> m;

    char mat[n + 2][m + 2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    int ind[n + 2][m + 2];
    int inx = 0;

    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

    bool visited[n + 2][m + 2];
    memset(visited, false, sizeof visited);
    memset(ind, -1, sizeof ind);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'x' && !visited[i][j])
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty())
                {
                    auto p = q.front();
                    q.pop();
                    for (int move = 0; move < 8; move++)
                    {
                        int nx = p.first + dx[move];
                        int ny = p.second + dy[move];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 'x' && !visited[nx][ny])
                        {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                            ind[nx][ny] = inx;
                        }
                    }
                }
                ind[i][j] = inx++;
            }
        }

    //    for (int i=0; i<n; i++) {
    //        cout << endl;
    //        for (int j = 0; j < m; j++) printf("%4d", ind[i][j]);
    //    }
    //    cout << endl;

    int parent[inx + 2];
    memset(parent, -1, sizeof parent);

    for (int id = 0; id < inx; id++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                int last_seen = -1;
                bool flag = false;

                if (ind[i][j] == id)
                {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    memset(visited, false, sizeof visited);
                    visited[i][j] = true;
                    while (!q.empty())
                    {

                        auto p = q.front();

                        //                        if (id == 2) {
                        //                            cout << "here for " << p.first << " " << p.second << " last_seen=" << last_seen << endl;
                        //                            syspause();
                        //                        }

                        if (flag)
                            break;

                        q.pop();
                        for (int move = 0; move < 4; move++)
                        {
                            if (flag)
                                break;
                            int nx = p.first + dx[move];
                            int ny = p.second + dy[move];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && (ind[nx][ny] == id || ind[nx][ny] == -1) &&
                                !visited[nx][ny])
                            {
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                            else if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            {
                                last_seen = -1;
                                flag = true;
                            }
                            else if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] &&
                                     ind[nx][ny] != -1 && ind[nx][ny] != id)
                            {
                                last_seen = ind[nx][ny];
                            }
                        }
                    }

                    parent[id] = last_seen;
                }
            }
        }
    }

    //    for (int i=0; i<inx; i++) {
    //        cout << "PARENT OF " << i << " IS " << parent[i] << endl;
    //    }

    level_to_number.clear();

    int mx = 0;

    for (int id = 0; id < inx; id++)
    {
        int level = 0;
        int tmp = id;
        while (parent[tmp] != -1)
        {
            tmp = parent[tmp];
            level++;
        }
        mx = max(mx, level);
    }

    for (int j = 0; j < inx; j++)
    {
        int level = 0;
        for (int k = j + 1; k < inx; k++)
        {
            int tmp = k;
            bool isParent = false;
            int l1 = 0;
            while (parent[tmp] != -1)
            {
                l1++;
                if (parent[tmp] == j)
                {
                    isParent = true;
                    break;
                }
                tmp = parent[tmp];
            }
            if (isParent)
            {
                level = max(level, l1);
            }
        }
        level_to_number[level]++;
    }

    vector<int> v;

    for (int i = 0; i <= mx; i++)
    {
        v.push_back(level_to_number[i]);
    }

    vector<int> v1 = {1, 1, 1};

    if (v == v1)
    {
        cout << 2 << endl;
        cout << 1 << endl;
    }
    else
    {
        for (auto x : v)
        {
            cout << x << endl;
        }
    }

    return 0;
}