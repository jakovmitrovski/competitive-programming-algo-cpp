#include <bits/stdc++.h>

using namespace std;

int pozicija[10002], potrosuvacka[10002], radius[10002];
int dp[102][10002];
bool iskoristeno[102][10002];
int dolzina, pari, n;

int rez(int kandelabri, int pari)
{
    if (kandelabri < 0 or pari <= 0)
        return 0;

    if (dp[kandelabri][pari] != -1)
        return dp[kandelabri][pari];

    int osvetleni_polinja = 2 * radius[kandelabri], ako_ja_zemam = 0, ako_ne_ja_zemam = 0;

    if (pozicija[kandelabri] + radius[kandelabri] >= dolzina)
        osvetleni_polinja -= pozicija[kandelabri] + radius[kandelabri] - dolzina;

    if (pozicija[kandelabri] - radius[kandelabri] < 0)
        osvetleni_polinja -= radius[kandelabri] - pozicija[kandelabri];

    if (pari >= potrosuvacka[kandelabri])
        ako_ja_zemam = rez(kandelabri - 1, pari - potrosuvacka[kandelabri]) + osvetleni_polinja;

    ako_ne_ja_zemam = rez(kandelabri - 1, pari);

    if (ako_ja_zemam > ako_ne_ja_zemam)
    {
        iskoristeno[kandelabri][pari] = true;
        dp[kandelabri][pari] = ako_ja_zemam;
    }

    else
        dp[kandelabri][pari] = ako_ne_ja_zemam;

    return dp[kandelabri][pari];
}

int main()
{
    cin >> dolzina >> pari >> n;

    for (int i = 0; i < n; i++)
        cin >> pozicija[i] >> potrosuvacka[i] >> radius[i];

    memset(dp, -1, sizeof(dp));
    memset(iskoristeno, false, sizeof(iskoristeno));

    cout << rez(n - 1, pari) << " ";

    int neosvetlen_interval = 0, osvetleno[100002];

    memset(osvetleno, 0, sizeof(osvetleno));

    for (int i = n - 1; i >= 0; i--)
        if (iskoristeno[i][pari] == true)
        {
            for (int j = max(0, pozicija[i] - radius[i]); j < min(dolzina, pozicija[i] + radius[i]); j++)
                osvetleno[j] = 1;

            pari -= potrosuvacka[i];
        }

    if (osvetleno[0] == 0)
        osvetleno[0] = 1;

    for (int i = 1; i < dolzina; i++)
    {
        if (osvetleno[i] == 0)
        {
            osvetleno[i] = osvetleno[i - 1] + 1;
            neosvetlen_interval = max(neosvetlen_interval, osvetleno[i]);
        }

        else
            osvetleno[i] = 0;
    }

    cout << neosvetlen_interval << endl;

    return 0;
}