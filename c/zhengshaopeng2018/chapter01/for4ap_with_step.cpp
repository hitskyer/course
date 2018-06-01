#include<iostream>
using namespace std;
int main()
{
     char flag = 'Y';
     while ('Y'==flag)
     {
          int n =0, sum = 0, i = 0 ;//定义初始化变量
          cout<<"请输入一个大于1的整数和步长值（步长值不能大于前面输入的整数哦）"<<endl;
          cin>> n >>i;
          for(int start = 1; start<=n; start +=i)//初始化；条件；运算表达式 start=start+2
          {
                sum += start;//sum =sum+ start 先加法后赋值到左侧变量
          }
          cout<<"从1到"<<n<<"的步长为"<<i<<"的等差数列的和是"<<sum<<endl;
          while(true)//认为下列条件为真，持续执行
          {
               cout<<"请输入Y/N"<<endl;
               cin>>flag;
               if('Y'==flag)
               {  
                     break;//退出该循环，跳到外循环，继续输入数字，执行运算
                }
                else if('N'==flag)
               {
                    return 0;//报告老板结束运算
               }
               else 
               {
                    continue;
               }
           }
      }
      return 0;
}
