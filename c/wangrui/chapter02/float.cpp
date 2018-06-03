#include<iostream>
#include<cmath>
using namespace std;
// 定义全局变量
float outer;
int main(){
     // 定义局部变量
     float inner;
     // 获取float型变量存储空间大小
     cout<< "float 型变量存储空间大小是： "<< sizeof(float) <<"  个字节。"<<endl;
     // 不初始化直接输出变量的值
     cout<<"不初始化直接输出函数体外变量值为： "<< outer <<endl;
     cout<<"不初始化直接输出函数体内变量值为： "<< inner <<endl;
     return 0;
}
