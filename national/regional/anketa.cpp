#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string niza[n + 2];

    for (int i = 0; i < n; i++)
        cin >> niza[i];

    string rez;
    int naj = 0;

    for (int i = 0; i < n; i++)
    {
        int br = 0;
        for (int j = 0; j < n; j++)
            if (niza[j] == niza[i])
                br++;

        if (br > naj)
        {
            naj = br;
            rez = niza[i];
        }
    }

    cout << rez << endl;
    return 0;
}