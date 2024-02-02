#include <iostream>
 
using namespace std;
 
int main()
{
    int a, b, c;
 
    cin >> a >> b >> c;
 
    int rez = 0;
 
    if ( ( b - a ) == 1 and ( c - b ) == 1)
    {
        cout<<0;
        return 0;
    }
 
    if ( (b - a) < (c - b) )
    {
        a=b+1;
        rez++;
        while ( (c-a != 1 and a<c) or (c-b != 1 and b<c) )
        {
              a+=2;
              b+=2;
              rez+=2;
 
            if ((a==c and b==c) or (a==c and b>c) or (a>c and b==c) or (a>c and b>c))
            {
                rez-=2;
                cout<<rez;
                return 0;
            }
            if ( a == c or b == c or a > c or b > c )
            {
                rez--;
                cout << rez;
                return 0;
            }
        }
    }
    else
    {
        c=b-1;
        rez++;
        while ( ( c - a != 1 and c > a ) or ( b - a != 1 and b > a ) )
        {
            c -= 2;
            b -= 2;
            rez += 2;
            if ((c == a and b == a) or (c == a and b < a) or (c < a and b == a) or (c < a and b < a))
            {
                rez -= 2;
                cout << rez;
                return 0;
            }
            if ( b == a or c == a or b < a or c < a )
            {
                rez--;
                cout << rez;
                return 0;
            }
        }
    }
 
    return 0;
}