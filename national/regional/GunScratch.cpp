#include <string>
#include <vector>
using namespace std;

class GunScratch
{
public:
    int matches(vector<string> v, string bullet)
    {

        for (int i = 0; i < v.size(); i++)
        {
            bool flag = false;
            for (int j = 0; j < v[i].size(); j++)
            {
                bool f = true;
                for (int k = 0, t = j; k < bullet.size(); k++, t++, t %= (v[i].size()))
                {
                    if (v[i][t] != bullet[k])
                    {
                        f = false;
                        break;
                    }
                }
                if (f)
                    return i;
            }
        }

        return -1;
    }
};