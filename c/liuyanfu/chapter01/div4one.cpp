#include <iostream>
using namespace std;

int main()
{
     cout<<"请输入两个整数进行除法，请注意第二个数不能为零！"<<endl;
     float a=0,b=0;
     cin>>a>>b;
     if(b==0)
      {  
         cout<<"分母为零不能计算，自动退出程序！"<<endl;
      }
     else
       cout<<"The result of   "<<   a  <<  "/"  <<   b   <<    "="     <<   a/b  <<endl;
     return 0;


}
