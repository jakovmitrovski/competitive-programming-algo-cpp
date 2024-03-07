#include <iostream>

using namespace std;

typedef long long ll;

ll niza[10000];
int n;
ll k;

void binary(ll pocetok, ll kraj)
{
    ll mid = (pocetok + kraj) / 2;

    ll zbir = 0;

    if (pocetok == kraj)
    {
        cout << pocetok;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        zbir += mid / niza[i];
    }

    if (zbir >= k)
        binary(pocetok, mid);

    if (zbir < k)
        binary(mid + 1, kraj);

    return;
}

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> niza[i];

    binary(0, 10000000000000000);

    return 0;
}