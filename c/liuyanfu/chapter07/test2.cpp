#include <iostream>

using namespace std;

void exchang(int a ,int b)
{
	cout << "被调函数所占内存空间：" << endl;
	cout << "形参变量a的地址为： " << &a << endl;	 
	cout << "形参变量b的地址为： " << &b << endl;
	cout << "交换之前a= "<< a << "\tb= "<< b << endl; 
	int temp = a;
	      a  = b;
	      b  = temp;
	cout << "交换之后a= " << a << "\tb= " << b << endl;
	cout << endl << endl;
}

void exchang1(int &a, int &b)
{
	cout << "形参为引用的子函数所在内存空间：" << endl;
	cout << "形参变量a的地址： " << &a << endl;
	cout << "形参变量b的地址： " << &b << endl;
	cout << "交换之前a= " << a << "\tb= " << b << endl;
	int temp = a;
	       a = b;
	       b = temp;
	cout << "交换之后a= " << a << "\tb= " << b << endl;
	cout << endl << endl;
}

int main()
{
	int a =10,b=5;
	cout << "主调函数所占内存空间： " << endl;
	cout << "实参变量a的地址为： " << &a << endl;
	cout << "实参变量b的地址为： " << &b << endl;
	cout << "交换前a= " << a << "\tb= " << b << endl; 
	cout << endl << endl;
	exchang(a,b);
	cout << "主调函数内存空间：" << endl;
	cout << "交换之后a= " << a << "\tb" << b << endl;
	cout << "第一次交换结束！" << endl << endl;
	exchang1(a,b);
	cout << "主调函数内存空间：" << endl;	
	cout << "交换之后a= " << a << "\tb" << b << endl;
	cout << "第二次交换结束！" << endl << endl;
	return 0;
}
