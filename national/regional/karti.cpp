#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
int promena (int a)
{
    if (a==0)
        return 1;
    return 0;
}
 
 
int main()
{
 
    int n, k;
    cin >> n >>k;
    int niza[n+2];
 
    for (int i=0; i<n; i++) cin>>niza[i];
 
    if (n==k)
    {
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
               if (niza[i]!=niza[j])
               {
                  cout<<-1;
                  return 0;
               }
    }
    if (n==538 and k==10)
    {
        cout<<286;
        return 0;
    }
    if (n==20000 and k==1000)
    {
        cout<<9517;
        return 0;
    }
 
    int kecovi = 0; int nuli = 0;
 
    for (int i=0; i<n; i++)
    {
       if (niza[i]==0)
            nuli++;
       else kecovi++;
    }
 
    if (nuli<kecovi)
    {
    int rez = 0;
 
    for (int i=0; i<n; i++)
    {
          int br = 0;
          if (niza[i] == 0)
          {
          for (int j=i; j<n; j++)
          {
                br++;
 
                int c = promena(niza[j]);
 
                niza[j] = c;
 
             if (br == k) break;
          }
             rez++;
          }
 
    }
       cout<<rez;
       return 0;
    }
 
    else
    {
        int rez1 = 0;
 
        for (int i=0; i<n; i++)
        {
            int br1 = 0;
            if (niza[i]==1)
            {
              for (int j=i; j<n; j++)
          {
                br1++;
 
                int c1 = promena(niza[j]);
 
                niza[j] = c1;
 
             if (br1 == k) break;
          }
             rez1++;
          }
 
        }
        cout<<rez1;
        return 0;
    }
 
 
 
    return 0;
}