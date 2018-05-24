#include <iostream>  
#include <climits>  
  
using namespace std;  
short b_var2;
int main()  
{  
   short b_var;
   short b_var3=0, b_var4=0;
   cout<<"b_var="<< b_var <<endl;
   cout<<"b_var2="<< b_var2 <<endl;
   cout << "signed short is " << sizeof(short) << " bytes." << endl;
   
   b_var3=32767;
   b_var4=-32768;
   cout<<"b_var3="<<b_var3<<endl;
   cout<<"b_var3+1="<<b_var3+1<<endl;
   cout<<"b_var4="<<b_var4<<endl;
   cout<<"b_var4-1="<<b_var4-1<<endl;
   return 0;  
}
