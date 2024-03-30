#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int niza[n];
    for (int i = 0; i < n; i++)
        cin >> niza[i];
    int mom = 0, rez = 1;
    for (int i = 0; i < n; i++)
    {
        if (mom + niza[i] <= m)
        {
            mom += niza[i];
        }
        else
        {
            mom = niza[i];
            rez++;
        }
    }
    cout << rez;
    return 0;
}