#include <iostream>  
#include <climits>  
  
using namespace std;  
bool b_var2;
int main()  
{  
   bool b_var;
   cout<<"b_var="<< b_var <<endl;
   cout<<"b_var2="<< b_var2 <<endl;
   cout << "signed bool is " << sizeof(bool) << " bytes." << endl;
   
   b_var2 = 0;
   cout<<"b_var2="<< b_var2 <<endl;
   b_var2 = 1;
   cout<<"b_var2="<< b_var2 <<endl;
   return 0;  
}
