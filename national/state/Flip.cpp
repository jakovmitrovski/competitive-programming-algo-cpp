#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

class Flip
{
public:
    int min(vector<string> start, vector<string> end)
    {
        map<vector<string>, bool> visited;
        map<vector<string>, int> steps;
        queue<vector<string>> q;

        q.push(start);
        visited[start] = true;
        steps[start] = 0;

        while (!q.empty())
        {

            vector<string> curr = q.front();

            q.pop();
            if (curr == end)
                return steps[curr];

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    vector<string> next = curr;
                    next[i][j] = next[i][j] == 'w' ? 'b' : 'w';
                    if (i > 0)
                        next[i - 1][j] = next[i - 1][j] == 'w' ? 'b' : 'w';
                    if (i < 3)
                        next[i + 1][j] = next[i + 1][j] == 'w' ? 'b' : 'w';
                    if (j > 0)
                        next[i][j - 1] = next[i][j - 1] == 'w' ? 'b' : 'w';
                    if (j < 3)
                        next[i][j + 1] = next[i][j + 1] == 'w' ? 'b' : 'w';
                    if (!visited[next])
                    {
                        visited[next] = true;
                        steps[next] = steps[curr] + 1;
                        q.push(next);
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    Flip f;
    cout << f.min({"wwwb", "bwbb", "wwwb", "bwbb"}, {"bwwb", "wwbb", "bwwb", "bwbw"});
    return 0;
}
