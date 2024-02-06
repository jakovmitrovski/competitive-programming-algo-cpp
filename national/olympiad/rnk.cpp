#include <bits/stdc++.h>
 
using namespace std;
 
int dp[201][201];
string s;
int n;
 
bool valid(char x, char y){
    return (x == 'A' && y == 'U') || (x == 'C' && y == 'G') || (x == 'G' && y == 'U');
}
 
int res(int left, int right) {
 
    if (right - left < 2) return 0;
 
    if (dp[left][right] != -1) return dp[left][right];
 
    int ans = 0;
 
    for (int i = left; i <= right; i++)
        for (int j = i + 2; j <= right; j++)
            if ((valid(s[i], s[j]) || valid(s[j], s[i]))) ans = max(ans, 1 + res(left, i - 1) + res(i + 1, j - 1) + res(j + 1, right));
 
    return dp[left][right] = ans;
}
 
 
int main() {
 
    cin >> n;
 
    cin >> s;
 
    memset(dp, -1, sizeof dp);
 
    cout << res(0, n);
 
    return 0;
 
}