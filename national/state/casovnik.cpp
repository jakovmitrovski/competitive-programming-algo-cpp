#include <bits/stdc++.h>

using namespace std;

int main()
{

    int h, m;

    cin >> h >> m;

    int k = 0, br = 0;

    for (int i = 1; i <= 10; i++)
    {
        k = m;

        m++;

        if (m <= 59)
        {

            int n = m;

            while (n > 0)
            {
                int c = k % 10;

                int c1 = n % 10;

                if (c != c1)
                    br++;

                n /= 10;

                k /= 10;
            }
        }

        if (m == 60)
        {
            m = 0;

            br += 2;

            if ((h > 0 and h < 9) or (h > 20 and h < 23) or (h > 10 and h < 19))
            {
                h++;
                br++;
            }

            else
            {
                if (h == 9)
                {
                    br += 2;

                    h++;
                }

                else if (h == 19)
                {
                    br += 2;

                    h++;
                }

                else if (h == 23)
                {
                    h = 0;

                    br += 2;
                }
            }
        }
    }

    cout << br;

    return 0;
}