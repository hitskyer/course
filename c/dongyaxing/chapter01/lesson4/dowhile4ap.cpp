#include <iostream>
using namespace std;


int main()
{
   char flag='y';
   do
    {
      cout<< "Enter one number n(n>=0)"<<endl;
      int sum=0,n=0,strat=1;
      cin >> n;
      do 
       {
        sum +=strat;
        strat ++;
       }while(strat<=n);
      cout << "the sum from 1 to" << n << "is : " << sum << endl;
      do
       {
        cout << "continue(y/N)" << endl;
        cin >> flag;
        if ('y' == flag)
               break;
        else if ('N' == flag)
               return 0;
             else
                continue;
       }while(true);
    }while('y' == flag);

   return 0;
}
