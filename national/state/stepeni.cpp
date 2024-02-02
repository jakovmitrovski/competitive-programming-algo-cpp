#include <iostream>
 
using namespace std;
 
int main()
{
    int n,s=0,i=0,a;
    cin>>n;
    while (s<n)
    {
        i++;
        s+=i;
    }
    s-=i;
    a=n-s;
    if (a==1 and s==0) cout<<1<<" "<<1;
    else if(a==1 and s!=0) cout<<1<<" "<<0;
    else if (a>1 and a<i) cout<<0<<" "<<0;
    else if (a==i) cout<<0<<" "<<1;
    return 0;
}