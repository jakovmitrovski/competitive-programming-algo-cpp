#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int a[n + 2];
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    float br = 0.0;
  
    for (int i = 0; i < n; i++) br += a[i];
    
    float ar = br / n;

    int ans = a[0];
    float d = a[0];
    
    float smallest = abs(d - ar);
    
    for (int i = 1; i < n; i++)
    {
        float c = abs(a[i] - ar);
        if (c < smallest)
        {
            smallest = c;
            ans = a[i];
        }
    }
    cout << ans;
    return 0;
}