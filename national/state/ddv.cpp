#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    string a;
    cin >> a;
    double b;
    cin >> b;
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string c;
        cin >> c;
        v.push_back(c);
    }
    double rez = 0.00000;
    bool dali_go_ima = false;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == a)
            dali_go_ima = true;
    }

    if (dali_go_ima == false)
        rez = b + (b * 0.18);
    else
        rez = b + (b * 0.05);

    cout << fixed;
    cout << setprecision(5) << rez;
    return 0;
}