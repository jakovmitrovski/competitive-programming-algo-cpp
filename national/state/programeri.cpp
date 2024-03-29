#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n, k, broj;

    long long rezultat = 0;
    cin >> n >> k;

    map<int, int> mapa;

    if (k == 0)
        for (int i = 0; i < n; i++)
        {
            cin >> broj;

            mapa[broj]++;

            rezultat += mapa[broj] - 1;
        }
    else
        for (int i = 0; i < n; i++)
        {
            cin >> broj;

            mapa[broj]++;

            rezultat += mapa[broj - k] + mapa[broj + k];
        }

    cout << rezultat;

    return 0;
}