#include <iostream>

using namespace std;

int fibonaci(int a, int b)
{
    int niza[100000], i = 2, br = 0;
    niza[0] = 1;
    niza[1] = 1;
    niza[i] = niza[i - 1] + niza[i - 2];
    while (i <= b)
    {
        niza[i] = niza[i - 1] + niza[i - 2];
        if (niza[i] >= a and niza[i] <= b)
            br++;
        i++;
    }
    if (a > 1)
        return br;
    if (a == 1)
        return br + 2;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int c = fibonaci(a, b);
    cout << c;
    return 0;
}