#include <iostream>
using namespace std;

	void print(short a)
	{
		cout << a << endl;
	}
	short b;
	int main()
	{
		short a;
		cout << "栈区变量 a 未初始化时的默认值： " << a << endl;
		cout << "short类型变量分配内存的长度：" << sizeof(a) << endl;
		print(b);
		a=32767;
		print(a);
		print(a+1);
		a=-32768;
		print(a);
		print(a-1);	
	}
