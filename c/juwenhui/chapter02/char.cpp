#include <iostream>  
#include <climits>  
  
using namespace std;  
char b_var2;
int main()  
{  
   char b_var;
   cout<<"b_var="<< b_var <<endl;
   cout<<"b_var2="<< b_var2 <<endl;
   cout << "signed char is " << sizeof(char) << " bytes." << endl;
   
    cout << "换行符\n: "<< "你好 \n 世界" << endl;
    cout <<"水平制表符\t: "<< "你好 \t 地球" <<endl;
    cout <<"纵向制表符\v: "<< "你好 \v 地球" <<endl;
    cout <<"退格符\b: "<< "你好\b 地球" <<endl;
    cout <<"回车符\r: "<< "你好 \r 地球" <<endl;
    cout <<"进纸符\f: "<< "你好 \f 地球" <<endl;
    cout <<"反斜线\\: "<< "你好 \\地球" <<endl;
    cout <<"报警符\a: "<< "你好 \a 地球" <<endl;
   return 0;  
}
