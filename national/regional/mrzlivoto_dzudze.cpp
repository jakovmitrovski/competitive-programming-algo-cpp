#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    cout << (n / b) - (n / a);

    return 0;
}