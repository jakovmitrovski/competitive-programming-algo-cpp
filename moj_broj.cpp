#include <iostream>
  
using namespace std;
  
int zbir_cifri (int n)
{
    int a = n%10; ///poslednata cifra
    int b = n/100; ///pravata cifra
    int c = (n/10)%10; ///srednata cifra
  
    return a+b+c;
}
  
int main()
{
    int ana[5] , stefan[5];
    //cin >> stefan[1] >> ana[1] >> stefan[2] >> ana[2] >> stefan[3] >> ana[3];
    for (int i=1; i<=3; i++)
        cin >> stefan[i] >> ana[i];
  
    ///da vidime koj kolku poeni ke ima
    int vkupno_ana = 0, vkupno_stefan = 0;
  
    for (int i=1; i<=3; i++)
    {
        int a = zbir_cifri(ana[i]);
        if (ana[i] % a == 0)
        {
            vkupno_ana += 2;
            vkupno_stefan--;
        }
        /// else nishto
  
        int b = zbir_cifri(stefan[i]);
        if (stefan[i] % b == 0)
        {
            vkupno_stefan += 2;
            vkupno_ana--;
        }
    }
  
    if (vkupno_ana > vkupno_stefan)
    {
        cout << vkupno_stefan << " " << vkupno_ana<<endl;
        cout << "Ana" << endl;
        return 0;
    }
    if (vkupno_stefan > vkupno_ana)
    {
        cout << vkupno_stefan << " " << vkupno_ana<<endl;
        cout<< "Stefan" << endl;
        return 0;
    }
  
    ///chim sme tuka znachi ednakvo poeni imaat
    ///treba da vidime koj kazal najgolem broj
  
    int najgolem = 0;
    string koj_go_kazal;
  
    for (int i=1; i<=3; i++)
    {
        if (ana[i] > najgolem)
        {
            najgolem = ana[i];
            koj_go_kazal = "Ana";
        }
  
        if (stefan[i] > najgolem)
        {
            najgolem = stefan[i];
            koj_go_kazal = "Stefan";
        }
    }
  
    cout << vkupno_stefan << " " << vkupno_ana<<endl;
    cout<< koj_go_kazal << endl;
  
    return 0;
}