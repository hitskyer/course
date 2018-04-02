#include <iostream>  
#include <climits>  
  
using namespace std;  
short b_var2;
int main()  
{  
   int b_var;
   int b_var3=0, b_var4=0;
   cout<<"b_var="<< b_var <<endl;
   cout<<"b_var2="<< b_var2 <<endl;
   cout << "signed int is " << sizeof(int) << " bytes." << endl;
   
   int amax=INT_MAX;
   int amin=INT_MIN;
   cout<<"int 最大值："<<amax<<endl;
   cout<<"int最大值+1:"<<amax+1<<endl;
   cout<<"int最小值："<<amin<<endl;
   cout<<"int最小值-1:"<<amin<<endl;
  
   return 0;  
}
