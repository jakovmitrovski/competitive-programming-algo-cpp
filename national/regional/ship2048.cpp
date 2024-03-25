#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Ship2048
{
public:
    vector<string> tiltRight(vector<string> v)
    {
        for (int i = 0; i < v.size(); i++)
            sort(v[i].begin(), v[i].end());
        return v;
    }

    vector<string> tiltLeft(vector<string> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            sort(v[i].begin(), v[i].end());
            reverse(v[i].begin(), v[i].end());
        }
        return v;
    }

    vector<string> tiltFront(vector<string> v)
    {

        for (int i = 0; i < v[0].size(); i++)
        {

            for (int j = 0; j < v.size(); j++)
                for (int k = j + 1; k < v.size(); k++)
                    if (v[j][i] < v[k][i])
                        swap(v[j][i], v[k][i]);
        }

        return v;
    }

    vector<string> tiltBack(vector<string> v)
    {

        for (int i = 0; i < v[0].size(); i++)
        {

            for (int j = 0; j < v.size(); j++)
                for (int k = j + 1; k < v.size(); k++)
                    if (v[j][i] > v[k][i])
                        swap(v[j][i], v[k][i]);
        }

        return v;
    }

    string KthRow(vector<string> cannonBalls, string tilts, int N, int K)
    {

        for (int t = 0; t < 2; t++)
        {
            for (int i = 0; i < tilts.size(); i++)
            {
                if (tilts[i] == 'L')
                {
                    cannonBalls = tiltLeft(cannonBalls);
                }
                else if (tilts[i] == 'F')
                {
                    cannonBalls = tiltFront(cannonBalls);
                }
                else if (tilts[i] == 'R')
                {
                    cannonBalls = tiltRight(cannonBalls);
                }
                else
                {
                    cannonBalls = tiltBack(cannonBalls);
                }
                //                for (int k=0; k<cannonBalls.size(); k++) cout << cannonBalls[k] << endl;
                //                cout << endl;
            }
        }

        return cannonBalls[K];
    }
};

int main()
{
    Ship2048 s = Ship2048();
    cout << s.KthRow({"11", "01", "00", "01"}, "RLFR", 2, 3) << endl;
    cout << s.KthRow({"01", "01", "10", "00", "11", "01"}, "RB", 3, 2) << endl;
    cout << s.KthRow({"100010", "000010", "111011", "101010", "101101", "000001"}, "LRF", 3, 4);
    return 0;
}