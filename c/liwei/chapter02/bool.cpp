#include <iostream>
using namespace std;
// 定义全局bool型变量
bool b;
int main() {
        // 定局部义bool型变量
        bool c;//将c定义bool型变量
       // 不进行初始化，直接输出b
         cout<<"b= "<< b <<endl;
         cout<<"c= "<< c <<endl;
        // 获取bool型变量存储空间大小。
    
        cout<< "bool 类型的存储空间大小是：   "
        << sizeof(bool)<<"  字节  "<<endl;
       // 输出bool值       
        b = 0;
	cout <<"b=  "<< b <<endl;
        b = 1;
        cout <<"b=  "<< b <<endl;
	
	//输出c 的bool值
	c=0;
	cout <<"c= "<< c <<endl;
	c=1;
	cout <<"c= "<< c <<endl;
	c=2;
	cout << "c= "<< c <<endl;
	return 0;
}
