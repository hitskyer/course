#include<iostream>

#include<string>

using namespace std;

int main()
{
  int x=0,y=0; //定义两个变量用来接收键盘输入的数字；
  char s ;// 定义字符类型变量，用来继续操作；
  
  do{

     cout<<"_______________________\n请输入两个数字做加法运算！\n";
     cin>>x>>y;
     cout<<"两数之和是： "<<x+y<<"\n";
     cout<<"请输入y或Y继续计算\n输入其他任意字符退出！\n";
     cin>>s;
     }
     while(s=='y'||s=='Y');
  
     return 0; 
     

}
