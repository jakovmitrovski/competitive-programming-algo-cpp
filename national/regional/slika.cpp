#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int br = 0, gr = 0;
    while (a < 3)
    {
        gr++;
        cin >> a;
        if (a < 2)
            br++;
        if (a == 2)
            break;
    }
    while (a < 3)
    {
        gr++;
        cin >> a;
    }
    int d = gr + 1;
    int b = d / br;
    cout << b << " " << br;

    return 0;
}