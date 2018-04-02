#include <iostream>  
#include <climits>
#include <cfloat>  
  
using namespace std;  
float b_var2;
int main()  
{  
   float b_var;
   cout<<"b_var="<< b_var <<endl;
   cout<<"b_var2="<< b_var2 <<endl;
   cout << "signed float is " << sizeof(float) << " bytes." << endl;
   
   float amax=FLT_MAX;
   float amin=FLT_MIN;
   cout<<"float 最大值："<<amax<<endl;
   cout<<"float最大值+1:"<<amax+1<<endl;
   cout<<"float最小值："<<amin<<endl;
   cout<<"float最小值-1:"<<amin<<endl;
  
   return 0;  
}
