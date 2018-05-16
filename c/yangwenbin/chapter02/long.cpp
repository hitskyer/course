#include<iostream>
#include<cmath>
using namespace std;
// 定义全局变量
long outer;
int main(){
   //定义局部变量
   long inner;
   long x=2,y=63;
   //获取long型变量的存储空间大小
   cout<<"获取long型变量的存储空间大小  "<< sizeof(long)<<"  个字节。"<<endl;
   //输出long型变量最大值最小值，最大值加1，最小值减1
   cout<<"long 型变量的最大值是： "<< pow(x,y)-1<<endl;
   cout<<"long 型变量的最小值是： "<< -pow(x,y)<<endl;
   cout<<"long 型变量的最大值+1 是： "<< pow(x,y)<<endl;
   cout<<"long 型变量的最小值 -1是： "<< -pow(x,y)-1<<endl;
   return 0;
}
