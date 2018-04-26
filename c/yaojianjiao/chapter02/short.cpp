#include<iostream>
using namespace std;
// 定义全局变量
short a;
int main(){
   
    //定义局部变量
    short b;
    short  c=0 ,d=0;
    cout<< "short 类型变量的存储大小是：  " <<sizeof(short)<<"  个字节" <<endl;
    cout<< "a= "<< a<<endl;
    cout<< "b= "<<b<<endl;
    c=32767;
    d=-32768;
    cout<<"c= "<< c <<endl;
    cout<<"c+1= "<< c+1 <<endl;
    cout<<"d= "<< d <<endl;
    cout<<"d-1= "<< d-1 <<endl;
    return 0;
    



}
