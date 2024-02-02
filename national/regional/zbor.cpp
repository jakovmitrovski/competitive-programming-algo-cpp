#include <iostream>
 
using namespace std;
 
bool samoglaska ( int a )
{
    if ( a == 'a' )
        return true;
    else if ( a == 'a' )
        return true;
    else if ( a == 'e' )
        return true;
    else if ( a == 'i' )
        return true;
    else if ( a == 'o' )
        return true;
    else if ( a == 'u' )
        return true;
    else return false;
 
}
 
int main()
{
    string a;
    cin >> a;
 
    int rez = 0;
 
    for (int i=0; i<a.size()-1; i++)
    {
       if ( samoglaska(a[i]) == false and samoglaska(a[i+1]) == false )
       {
           rez++;
       }
    }
 
    cout << rez;
 
    return 0;
}