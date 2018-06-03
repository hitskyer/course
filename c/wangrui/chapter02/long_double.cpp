#include<iostream>
using namespace std;
// 定义全局变量
long double outer;
int main(){
       // 定义局部变量
       long double inner;
       // 获取long double 类型的变量需要存储空间大小
       cout<<"long double 类型的变量存储空间大小是： "<<sizeof(long double) <<endl;
       
       cout <<"不初始化函数体外变量输出值为： "<<outer <<endl;
       cout <<"不初始化函数体内变量输出值为： "<<inner <<endl;
       return 0;


}
