#include <iostream>
using namespace std;

	void print(int a)
	{
		cout << a << endl;
	}
	int a ;
	int main()
	{
		int b;
		cout << "int类型的全局变量的默认值： " ;
		print(a);
		cout << "int类型的局部变量的默认值： " ;
		print(b);
		cout << "int型变量的存储长度： " << sizeof(a) << endl;
		a=2147483647;
		print(a);
		print(a+1);
		b=-2147483648;
		print(b);
		print(b-1);	
		return 0;
	}
