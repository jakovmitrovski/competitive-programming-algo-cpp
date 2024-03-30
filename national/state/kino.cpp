#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;

typedef long long ll;

ll mnozi_po_mod(ll a, ll b, ll modul)
{

    ll k = b / 10;

    if (k == 0)
        return (a * b) % modul;

    else
    {
        ll d, e, f;
        d = b % 10;
        e = (a * d) % modul;
        f = (a * 10) % modul;
        return (e + mnozi_po_mod(f, k, modul)) % modul;
    }
}

ll form(ll n, ll m, ll d)
{
    ll s = 1;
    for (ll i = 0; i < d; i++)
        s = mnozi_po_mod(n - i, s, MOD);
    // cout << s << " ";
    for (ll i = 0; i < m - d; i++)
    {
        s = (s * (n - d)) % MOD;
        // cout << s << " ";
    }
    // cout << endl;
    return s % MOD;
}

int main()
{
    ll n, m, d;
    cin >> n >> m >> d;

    if (d >= n && m > n)
    {
        cout << 0;
        return 0;
    }

    // kobinacii n nad i presmetuvam
    ll dp[n + 2][m + 2];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][i] = dp[i][0] = 1;

    for (ll i = 2; i <= n; i++)
        for (ll j = 1; j <= i - 1; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;

    /*for (int i=0; i<=n; i++){
        cout << endl;
        for (int j=0; j<=m; j++) cout << dp[i][j] << " ";
    }*/

    ll rez = 0;

    // AKO SE ISTI E PERMUTACII.
    if (n == m)
    {
        rez = 1;
        for (ll i = 0; i < m; i++)
            rez = mnozi_po_mod(n - i, rez, MOD);
        cout << rez;
        return 0;
    }

    // AKO NE SE.....n nad i * (n-i)!/(n-d)! * (n-d)^((m-d)-1)
    for (ll i = 0; i <= n - d - 1; i++)
    {
        ll a = mnozi_po_mod(dp[n][i], form(n - i, m, d), MOD);
        // cout << "form e " << form(n-i, m, d) << " dp[" << n << "][" << i << "] = " << dp[n][i] << " pomnozeni se " << a << endl;
        rez = rez + pow(-1, i) * a;
        rez %= MOD;
    }

    if (rez < 0)
        rez += MOD;

    cout << rez << endl;

    return 0;
}