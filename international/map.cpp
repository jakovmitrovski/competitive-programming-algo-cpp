#include<bits/stdc++.h>
 
using namespace std;
 
int main ()
{
    string s;
    getline (std::cin, s);
 
    double dist = 0.0;
 
    int x = 0, y = 0;
 
    for (int i=0; i<s.size(); i++){
        int br = 0;
        if (s[i] == 'e' || s[i] == 'E'){
            i++;
            if (i == s.size()) break;
            if (s[i] >= '0' && s[i] <= '9'){
                br = s[i] - '0';
            }
            i++;
            if (i == s.size()) break;
            if (s[i] >= '0' && s[i] <= '9'){
                br = 10 * br + (s[i] - '0');
            }else{
                i--;
            }
            x += br;
        }
        else if (s[i] == 'w' || s[i] == 'W'){
            i++;
            if (i == s.size()) break;
            if (s[i] >= '0' && s[i] <= '9'){
                br = s[i] - '0';
            }
            i++;
            if (i == s.size()) break;
            if (s[i] >= '0' && s[i] <= '9'){
                br = 10 * br + (s[i] - '0');
            }else{
                i--;
            }
            x -= br;
        }
        else if (s[i] == 's' || s[i] == 'S'){
            i++;
            if (i == s.size()) break;
            if (s[i] >= '0' && s[i] <= '9'){
                br = s[i] - '0';
            }
            i++;
            if (i == s.size()) break;
            if (s[i] >= '0' && s[i] <= '9'){
                br = 10 * br + (s[i] - '0');
            }else{
                i--;
            }
            y -= br;
        }
        else if (s[i] == 'n' || s[i] == 'N'){
            i++;
            if (i == s.size()) break;
            if (s[i] >= '0' && s[i] <= '9'){
                br = s[i] - '0';
            }
            i++;
            if (i == s.size()) break;
            if (s[i] >= '0' && s[i] <= '9'){
                br = 10 * br + (s[i] - '0');
            }else{
                i--;
            }
            y += br;
        }
 
    }
    dist = sqrt((x * x) + (y * y));
    cout << fixed;
    cout << setprecision(2) << dist << endl;
 
    return 0;
}