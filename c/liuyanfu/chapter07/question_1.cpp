#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	int a1 = 5;
	int a2 = 6;
	//int *b = &a;
	int &c = a;
	int &c1 = a1;
	int d = 20;
	cout << "int型变量a的地址： " << &a << endl;
	cout << "a1地址为： " << &a1 << endl;
	cout << "a2地址为： " << &a2 << endl;
	//cout << "指针变量b的地址： " << &b << endl;
	//cout << "第一个和第二个变量之间存储地址的差值： " << &b - &a << endl;
	cout << "引用型变量c的地址： " << &c << endl;
	cout << "引用型变量c1的地址： " << &c1 << endl;
	//cout << "第二个和第三个变量之间存储地址的差值： " << &c - &b << endl;
	cout << "int型变量d的地址： " << &d << endl;
	//cout << "第三个和第四个变量之间存储地址的差值： " << &d - &c << endl;
	return 0;
}
