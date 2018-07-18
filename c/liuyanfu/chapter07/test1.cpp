#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	int &b= a;
	cout << "变量a的地址：" << &a << endl;
	cout << "引用型变量的地址：" << &b << endl;
	return 0;
}
