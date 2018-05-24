#include <iostream>
#include <math.h>
using namespace std;

	void print(long l)
	{
		cout << l << endl;
	}
	long l;
	int main()
	{
		long a;
		cout << "long类型的局部变量的默认值： " ;
		print(a);
		cout << "long类型的局部变量的默认值： " ;
		print(l);
		cout << "long类型变量的存储长度： " << sizeof(a) << endl;
		a=pow(2,32)-1;
		print(a);
		print(a-1);
		l=-1*(a+1);
		print(l);
		print(l-1);
		return 0;
	}
