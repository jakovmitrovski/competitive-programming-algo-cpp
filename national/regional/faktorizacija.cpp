#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int stepen = 0;
        while (n % i == 0)
        {
            stepen++;
            n /= i;
        }
        if (stepen > 0)
        {
            if (n != 1)
                cout << "(" << i << "^" << stepen << ")"
                     << "*";
            else
                cout << "(" << i << "^" << stepen << ")";
        }
    }
    return 0;
}