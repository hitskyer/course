#include <iostream>
using namespace std;

int main()
{

	int ival=1.01;
	int &rval2=ival;
	const int &rval3=1;
//a) 
	rval2=3.14159;
	cout << "rval2= " << rval2 << endl;
//b) 
	rval2=rval3;
	cout << "rval2= " << rval2 << endl;
//c)
	ival=rval3;
	cout << "ival= " << ival << endl;
//d)  错误：rval3 是const 不能重新赋值
	rval3=ival;  
}
