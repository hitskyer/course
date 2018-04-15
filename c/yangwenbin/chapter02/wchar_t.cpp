#include<iostream>

using namespace std;
// 定义全局变量 
wchar_t outer;
int main(){
  //获取宽字符存储空间大小
  cout<<"wchar_t 型的变量存储空间大小是： "<< sizeof(wchar_t)<<"  个字节。"<<endl;
  //定义局部变量
  wchar_t inner;
  cout<< "不初始化直接输出函数体外变量为： "<< outer <<endl;
  cout<< "不初始化直接输出函数体内变量为： "<< inner <<endl;
  return 0;

}
