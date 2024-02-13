#include <limits.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <set>

using namespace std;
string dp[101][101];
class SnakeEggs
{
public:
    string eggs;
    string rek(int sz, int k)
    {
        //  cout << sz <<" "<< k <<endl;
        if (dp[sz][k] != "-")
            return dp[sz][k];
        if (sz == 0 || k == sz)
        {
            dp[sz][k] = "";
            return "";
        }
        if (k == 0)
        {
            dp[sz][k] = eggs.substr(eggs.size() - sz, sz);
            return dp[sz][k];
        }
        /*if(k>sz){
            dp[sz][k]=".";
            return ".";
        }*/
        string kraj = max(rek(sz - 1, k - 1), eggs[eggs.size() - sz] + rek(sz - 1, k));
        dp[sz][k] = kraj;
        // cout << eggs.substr(eggs.size()-sz, sz)<<" "<< k <<" "<< kraj<<endl;;
        return kraj;
    }
    string getLargest(string Eggs, int K)
    {
        eggs = Eggs;
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                dp[i][j] = "-";
        return rek(eggs.size(), K);
    }
};