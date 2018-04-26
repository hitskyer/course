#include <iostream>  
#include <climits>  
  
using namespace std;  
long b_var2;
int main()  
{  
   long b_var;
   cout<<"b_var="<< b_var <<endl;
   cout<<"b_var2="<< b_var2 <<endl;
   cout << "signed long is " << sizeof(long) << " bytes." << endl;
   
   long amax=LONG_MAX;
   long amin=LONG_MIN;
   cout<<"long 最大值："<<amax<<endl;
   cout<<"long最大值+1:"<<amax+1<<endl;
   cout<<"long最小值："<<amin<<endl;
   cout<<"long最小值-1:"<<amin<<endl;
  
   return 0;  
}
