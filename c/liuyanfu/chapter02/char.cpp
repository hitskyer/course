#include <iostream>

using namespace std;

	void print(char c)
	{
		cout << c << endl;
	}
	char c;
	int main()
	{
		char a;
		cout << "char类型的全局变量的默认值： ";
		print(c);
		cout << "char类型的局部变量的默认值： ";
		print(a);
		cout << a << "  存储长度是： " << sizeof(a) << endl;
		print(c);
		a='\n';
		print(a);
		a='\t';
		print(a);
		a='\a';
		print(a);
		return 0;	
	}
