#include<string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

map<string, bool> visited;
int win0 = 0, winX = 0, draw = 0, cnt = 0;

bool check(string s){
    if (s[0] == s[3] and s[3] == s[6] and s[0] =='x') {
        winX++;
        return true;
    }
    if (s[1] == s[4] and s[4] == s[7] and s[1] =='x') {
        winX++;
        return true;
    }
    if (s[2] == s[5] and s[5] == s[8] and s[2] =='x') {
        winX++;
        return true;
    }
    if (s[0] == s[1] and s[1] == s[2] and s[0] =='x') {
        winX++;
        return true;
    }
    if (s[3] == s[4] and s[4] == s[5] and s[3] =='x') {
        winX++;
        return true;
    }
    if (s[6] == s[7] and s[7] == s[8] and s[6] =='x') {
        winX++;
        return true;
    }
    if (s[2] == s[4] and s[4] == s[6] and s[2] =='x') {
        winX++;
        return true;
    }
    if (s[0] == s[4] and s[4] == s[8] and s[0] =='x') {
        winX++;
        return true;
    }
    if (s[0] == s[3] and s[3] == s[6] and s[0] =='o') {
        win0++;
        return true;
    }
    if (s[1] == s[4] and s[4] == s[7] and s[1] =='o') {
        win0++;
        return true;
    }
    if (s[2] == s[5] and s[5] == s[8] and s[2] =='o') {
        win0++;
        return true;
    }
    if (s[0] == s[1] and s[1] == s[2] and s[0] =='o') {
        win0++;
        return true;
    }
    if (s[3] == s[4] and s[4] == s[5] and s[3] =='o') {
        win0++;
        return true;
    }
    if (s[6] == s[7] and s[7] == s[8] and s[6] =='o') {
        win0++;
        return true;
    }
    if (s[2] == s[4] and s[4] == s[6] and s[2] =='o') {
        win0++;
        return true;
    }
    if (s[0] == s[4] and s[4] == s[8] and s[0] =='o') {
        win0++;
        return true;
    }

    for (char c: s)
        if (c == '?') return false;

    draw++;
    return true;
}

class DumbTicTacToe
{
public:
    string getChances(vector<string> map)
    {
        string state = "";

        for (string s : map) {
            state += s;
            for (char c : s){
                if (c != '?') cnt++;
            }
        }
        bool moveX = (cnt) % 2 != 1;
        queue<pair<string,bool> > q;
        q.push({state, moveX});

        while(!q.empty()){
            string curr = q.front().first;
            bool turn = q.front().second;
            q.pop();
            //cout << curr << endl;
            //system("pause");

            if (turn){
                for (int i=0; i<9; i++) {
                    if (curr[i] == '?'){
                        string newState = curr;
                        newState[i] = 'x';
                        if (!check(newState)) {
                            visited[newState] = true;
                            q.push({newState, !turn});
                        }
                    }
                }
            }else{
                for (int i=0; i<9; i++) {
                    if (curr[i] == '?'){
                        string newState = curr;
                        newState[i] = 'o';
                        if (!check(newState)){
                            visited[newState] = true;
                            q.push({newState, !turn});
                        }
                    }
                }
            }
        }
        //cout << winX << " " << win0 << " " << draw << endl;
        string rez = "";
        if (moveX){
            double ret = (winX/((winX+win0+draw)*1.0));
            ret += 0.0005;
            //cout << ret << endl;
            int k = (int)(ret*1000);
            //cout << k << endl;
            rez = to_string(k/10)+"."+to_string(k%10) +"%";
        }else{
            double ret = (win0/((winX+win0+draw)*1.0));
            ret += 0.0005;
            //cout << ret << endl;
            int k = (int)(ret*1000);
            //cout << k << Endll
            rez = to_string(k/10)+"."+to_string(k%10) +"%";
        }

        return rez;
    }
};