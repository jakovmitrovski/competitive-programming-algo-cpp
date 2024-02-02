#include <bits/stdc++.h>
 
using namespace std;
 
int mat[256][256];
int rowOf[33000];
int colOf[33000];
 
int neigh(int ax, int ay, int bx, int by) {
 
    if (ax == bx) {
        return abs(ay - by);
    }
 
    if (ax > bx) {
        swap(ax, bx);
        swap(ay, by);
    }
 
    int left = 1 << 25, right = 1 << 25;
    int left_x = ax, left_y = ay;
    int right_x = ax, right_y = ay;
    int num = 0;
 
    while (true) {
        if (left_x > bx || left_y != by) {
            left = 1 << 25;
            break;
        }
 
        if (left_x == bx && left_y == by) {
            left = num;
            break;
        }
        left_x++;
        num++;
    }
 
    num = 0;
 
    while (true) {
        if (right_x > bx || right_y > by) {
            right = 1 << 25;
            break;
        }
        if (right_x == bx && right_y == by) {
            right = num;
            break;
        }
        right_x++;
        right_y++;
        num++;
    }
 
    if (left == 1 << 25 && right == 1 << 25) return -1;
 
    return min(left, right);
}
 
bool checkSome(const vector<int> &v) {
 
    vector<pair<int, int> > coords;
    coords.reserve(v.size());
    for (int i : v) coords.emplace_back(rowOf[i], colOf[i]);
 
    int dist = neigh(coords[0].first, coords[0].second, coords[1].first, coords[1].second);
 
    if (dist == -1) return false;
 
    for (int i = 1; i < v.size(); i++) {
        int d2 = neigh(coords[i].first, coords[i].second, coords[(i + 1) % v.size()].first,
                       coords[(i + 1) % v.size()].second);
        if (d2 == -1 || d2 != dist) return false;
    }
 
    return true;
}
 
 
void check(vector<int> v, int k) {
 
    sort(v.begin(), v.end());
 
    do {
        if (k == 3) {
            if (checkSome(v)) {
                cout << "TRIAGOLNIK" << endl;
                return;
            }
        } else if (k == 4) {
            if (checkSome(v)) {
                cout << "PARALELOGRAM" << endl;
                return;
            }
        } else {
            if (checkSome(v)) {
                cout << "SESTOAGOLNIK" << endl;
                return;
            }
        }
    } while (next_permutation(v.begin(), v.end()));
 
    cout << "NISTO" << endl;
}
 
 
int main() {
 
    int n;
    cin >> n;
 
    int id = 1;
    for (int i = 0; i < 256; i++)
        for (int j = 0; j < i + 1; j++) {
            rowOf[id] = i;
            colOf[id] = j;
            mat[i][j] = id++;
        }
 
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
 
        vector<int> v;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
 
        if (k > 6 || k == 5) {
            cout << "NISTO" << endl;
            continue;
        } else check(v, k);
         
    }
 
    return 0;
}