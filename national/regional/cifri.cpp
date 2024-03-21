#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int niza[10] = {0};
    for (int i = a; i <= b; i++)
    {
        int c = 0, g = i;
        while (g > 0)
        {
            niza[g % 10]++;
            g /= 10;
        }
    }
    for (int i = 0; i < 10; i++)
        cout << niza[i] << " ";
    return 0;
}