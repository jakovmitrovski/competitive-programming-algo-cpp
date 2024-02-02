#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
vector <int> v;
 
int main()
{
    int n;
    cin >> n;
 
    for (int i=0; i<((n*(n+1))/2); i++)
    {
        int a;
        cin >> a;
 
        v.push_back(a);
    }
 
    for (int i=n-1; i>=0; i--)
     
        for (int j=((i-1)*i)/2; j<((i*(i-1))/2)+i; j++)
            
            v[j] += max( v[j+i], v[j+i+1] );
 
    reverse(v.end(),v.begin());
 
    cout<<v[0];
 
    return 0;
}