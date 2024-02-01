#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int smallest = 1 << 30, biggest = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        string word;

        cin >> num >> word;
        
        if (word == "DA")
        {
            if (num < smallest)
                smallest = num;
        }
        else
        {
            if (num > biggest)
                biggest = num;
        }
    }
    cout << (biggest + 1) << " " << smallest - 1;

    return 0;
}