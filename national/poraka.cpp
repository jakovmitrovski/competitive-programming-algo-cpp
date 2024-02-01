#include <iostream>
 
using namespace std;
 
string funkcija (string s, string s1)
{
    int i = 0, j = 0;
 
    int rez = 0;
 
    while (i < s.size() and j < s1.size())
    {
        if (s[i] == s1[j])
        {
            i++;
            j++;
 
            rez++;
        }
 
        else j++;
    }
 
    if ( rez == s.size())
 
        return "DA";
 
    return "NE";
}
 
int main()
{
    int n;
 
    cin >> n;
 
    string s[n+2];
 
    string s1[n+2];
 
    for (int i=0; i<n; i++)
    {
        cin >> s[i] >> s1[i];
    }
 
 
    for (int k=0; k < n; k++)
    {
       cout << funkcija (s[k], s1[k]) << endl;
    }
 
    return 0;
}