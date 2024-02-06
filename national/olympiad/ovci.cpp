#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
 
    int n,m;
 
    cin >> n >> m;
 
    char mat[n+2][m+2];
 
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) cin >> mat[i][j];
 
    bool visited[n+2][m+2];
 
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) visited[i][j] = false;
 
    int vk_ovci = 0;
    int vk_volci = 0;
 
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
         if (mat[i][j]!='#'  and visited[i][j] == false)
        {
            queue<pair<int,int> >q;
 
            pair <int,int> par;
 
            par.first = i;
            par.second = j;
 
            q.push(par);
 
            visited[i][j] = true;
 
            int ovci = 0, volci = 0;
 
            ///cout << "pusta od "<<i<<" "<<j<<endl;
 
            while (!q.empty())
            {
                pair<int,int> p;
 
                p = q.front();
 
                q.pop();
 
                int x, y;
 
                x = p.first;
 
                y = p.second;
 
 
                if (mat[x][y] == 'o')
                    ovci++;
 
                if (mat[x][y] == 'v')
                    volci++;
 
                if (x>0 and mat[x-1][y] != '#' and visited[x-1][y] == false)
                {
                    visited[x-1][y] = true;
 
                    pair <int,int> p1;
 
                    p1.first = x-1;
                    p1.second = y;
 
                    q.push(p1);
 
                }
 
                if (x < n-1 and mat[x+1][y] != '#' and visited[x+1][y] == false)
                {
                    visited[x+1][y] = true;
 
                    pair <int,int> p1;
 
                    p1.first = x+1;
                    p1.second = y;
 
                    q.push(p1);
 
                }
 
                if (y>0 and mat[x][y-1] != '#' and visited[x][y-1] == false)
                {
                    visited[x][y-1] = true;
 
                    pair <int,int> p1;
 
                    p1.first = x;
                    p1.second = y-1;
 
                    q.push(p1);
 
                }
 
                if (y < m-1 and mat[x][y+1] != '#' and visited[x][y+1] == false)
                {
                    visited[x][y+1] = true;
 
                    pair <int,int> p1;
 
                    p1.first = x;
                    p1.second = y+1;
 
                    q.push(p1);
 
                }
 
 
            }
 
            ///cout << "izbroja "<<ovci<<" ovci i "<<volci<<" volci" <<endl;
 
            if (ovci > volci) vk_ovci += ovci;
 
            else vk_volci += volci;
        }
 
        cout << vk_ovci << " " << vk_volci;
 
    return 0;
}