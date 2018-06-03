#include<iostream>
#include<cmath>
using namespace std;
// 定义全局变量
int outer;
int main(){
   //获取int型存储大小
   cout<< "int 型存储大小是： "<< sizeof(int)<<"  个字节"<< endl;
   //定义局部变量
   int inner;
   cout<< "函数体外未初始化的值为："<< outer <<endl;
   cout<< "函数体内未初始化的值为："<< inner <<endl;
   int x=2,y=31;
   cout<< "int 类型最大值为：" << pow(x,y)-1 <<endl;
   cout<< "int 类型最小值为：" << -pow(x,y) <<endl;
   cout<< "int 类型最大值 +1 为：" << pow(x,y) <<endl;
   cout<< "int 类型最小值-1 为：" << -pow(x,y)-1 <<endl;

   return 0; 
}
