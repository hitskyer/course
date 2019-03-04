#include<iostream>
using namespace std;
int main()
{
    float money,avgmoney=0;
    int i = 0;
    while(cin >> money && i != 12)
    {
        avgmoney += money;
        ++i;
   }
   cout << "$" << avgmoney/12 << endl;
}