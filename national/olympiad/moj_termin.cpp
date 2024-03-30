#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int L;
    cin >> L;

    vector<string> O;
    O.resize(L + 1);

    for (int i = 1; i <= L; i++)
        cin >> O[i];

    int options[L + 1];
    options[0] = 1;

    for (int i = 1; i <= L; i++)
    {
        options[i] = 0;

        for (int sz = 1; sz <= i; sz++)
        {
            bool good = true;
            int from = i - sz + 1, to = i;
            for (int j = from; j <= to; j++)
            {
                if (O[j] != "N" && stoi(O[j]) != sz)
                {
                    good = false;
                    break;
                }
            }

            if (good)
            {
                options[i] = options[i] + options[i - sz];

                if (options[i] > 1)
                {
                    options[i] = 2;
                }
            }
        }
    }

    if (options[L] == 1)
        cout << "DA" << endl;

    else
        cout << "NE" << endl;

    return 0;
}