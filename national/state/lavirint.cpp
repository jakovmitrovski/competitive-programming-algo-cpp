#include <bits/stdc++.h>

using namespace std;

char mat[301][301];
int dp[4][301][301];
int n, m;

bool valid(int nx, int ny)
{
    return nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] != '#';
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    int sx = 0, sy = 0, ex = 0, ey = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'P')
            {
                sx = i;
                sy = j;
            }
            if (mat[i][j] == 'K')
            {
                ex = i;
                ey = j;
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    queue<pair<int, pair<int, int>>> q;

    q.push({1, {sx, sy}});

    for (int k = 0; k < 4; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dp[k][i][j] = 1 << 25;

    dp[1][sx][sy] = 0;

    while (!q.empty())
    {
        auto curr = q.front();
        int x = curr.second.first, y = curr.second.second;
        q.pop();

        if (x == ex && y == ey)
        {
            cout << dp[curr.first][x][y];
            return 0;
        }

        if (curr.first == 1)
        {
            for (int move1 = 0; move1 < 4; move1++)
            {
                int nx = x + dx[move1], ny = y + dy[move1], nstep = (curr.first % 3) + 1;
                if (valid(nx, ny) && dp[nstep][nx][ny] > dp[curr.first][x][y] + 1)
                {
                    dp[nstep][nx][ny] = dp[curr.first][x][y] + 1;
                    q.push({nstep, {nx, ny}});
                }
            }
        }
        else if (curr.first == 2)
        {
            for (int move1 = 0; move1 < 4; move1++)
            {
                int nx = x + dx[move1], ny = y + dy[move1], nstep = (curr.first % 3) + 1;
                if (valid(nx, ny))
                {
                    for (int move2 = 0; move2 < 4; move2++)
                    {
                        if (move2 != move1)
                            continue;
                        int nx2 = nx + dx[move2], ny2 = ny + dy[move2];
                        if (valid(nx2, ny2) && dp[nstep][nx2][ny2] > dp[curr.first][x][y] + 1)
                        {
                            dp[nstep][nx2][ny2] = dp[curr.first][x][y] + 1;
                            q.push({nstep, {nx2, ny2}});
                        }
                    }
                }
            }
        }
        else if (curr.first == 3)
        {
            for (int move1 = 0; move1 < 4; move1++)
            {
                int nx = x + dx[move1], ny = y + dy[move1], nstep = (curr.first % 3) + 1;
                if (valid(nx, ny))
                {
                    for (int move2 = 0; move2 < 4; move2++)
                    {
                        if (move2 != move1)
                            continue;
                        int nx2 = nx + dx[move2], ny2 = ny + dy[move2];
                        if (valid(nx2, ny2))
                        {
                            for (int move3 = 0; move3 < 4; move3++)
                            {
                                if (move3 != move2)
                                    continue;
                                int nx3 = nx2 + dx[move3], ny3 = ny2 + dy[move3];
                                if (valid(nx3, ny3) && dp[nstep][nx3][ny3] > dp[curr.first][x][y] + 1)
                                {
                                    dp[nstep][nx3][ny3] = dp[curr.first][x][y] + 1;
                                    q.push({nstep, {nx3, ny3}});
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}