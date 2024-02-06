#include <iostream>
 
using namespace std;
 
int main()
{
    int a,b;
    cin>>a>>b;
    int br=0;
    for (int i=a; i<=b; i++)
    {
        if (i%2==1)
            br+=i;
    }
    cout<<br;
    return 0;
}