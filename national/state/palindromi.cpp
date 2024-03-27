#include <bits/stdc++.h>

using namespace std;

bool palindrom(int n)
{
    vector<int> v1;

    while (n > 0)
    {
        v1.push_back(n % 10);

        n /= 10;
    }

    vector<int> v2 = v1;
    reverse(v2.begin(), v2.end());

    if (v1 == v2)
        return true;

    return false;
}

int main()
{
    int a, b;

    cin >> a >> b;

    vector<int> v;

    for (int i = 1; i <= 99999; i++)
    {
        if (palindrom(i) == true)
            v.push_back(i);
    }

    bool visited[100000];

    memset(visited, false, sizeof(visited));

    visited[a] = true;

    int cekori[100000];

    memset(cekori, -1, sizeof(cekori));

    queue<int> q;

    cekori[a] = 0;

    q.push(a);

    while (visited[b] != true)
    {
        int teme = q.front();

        q.pop();

        for (int i = 0; i < v.size(); i++)
        {
            int zbir = teme;

            if (v[i] > zbir)
                break;

            zbir += v[i];

            if (visited[zbir] == false)
            {

                visited[zbir] = true;

                cekori[zbir] = cekori[teme] + 1;

                q.push(zbir);
            }
        }
    }

    cout << cekori[b];

    return 0;
}