#include <iostream>

using namespace std;

int main()
{
    int br1 = 0, br2 = 0;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        br1 += a;
        br2 += b;
    }

    if (br1 > br2)
    {
        cout << "zelka" << endl;
        cout << br1;
    }

    else
    {
        cout << "morkov" << endl;
        cout << br2;
    }

    return 0;
}