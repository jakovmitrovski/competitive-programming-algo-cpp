#include <bits/stdc++.h>
 
using namespace std;
 
double dist(int ax, int ay, int bx, int by) {
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}
 
bool isTriangle(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    double a = dist(p1.first, p1.second, p2.first, p2.second);
    double b = dist(p1.first, p1.second, p3.first, p3.second);
    double c = dist(p2.first, p2.second, p3.first, p3.second);
 
    vector<double> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
 
    if (a + b > c && a + c > b && b + c > a) {
        if (abs(v[2] * v[2] - (v[1] * v[1] + v[0] * v[0])) < 0.0001) return true;
        else return false;
    } else return false;
 
}
 
int main() {
 
    int n;
    cin >> n;
 
    vector<pair<int, int> > v;
 
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
 
    int ans = 0;
 
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++) 
                if (isTriangle(v[i], v[j], v[k])) ans++;
                 
    cout << ans << endl;
 
    return 0;
}