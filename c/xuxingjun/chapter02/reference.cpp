#include <iostream>
using namespace std;

int main() {
	int ival = 1024;
	// 引用的声明、定义、初始化，一步搞定，且不能解绑
	int &refVal = ival; 
	//err : int &refVal2;
	//err : int &refVal3 = 10;

	//引用与赋值的关键区别：引用是别名，赋值是两个变量
	int jval = ival;
	cout << "----------------" << endl;
	cout << "ival = " << ival << endl;
	cout << "refVal = " << refVal << endl;
	cout << "jval = " << jval << endl;

	refVal++;
	cout << "----------------" << endl;
	cout << "ival = " << ival << endl;
	cout << "refVal = " << refVal << endl;
	cout << "jval = " << jval << endl;

	ival++;
	cout << "----------------" << endl;
	cout << "ival = " << ival << endl;
	cout << "refVal = " << refVal << endl;
	cout << "jval = " << jval << endl;

	//const引用可以绑定const型、非const型、常量、表达式
	const int &ref1 = ival;
	cout << "----------------" << endl;
	cout << "ref1 = " << ref1 << endl;

	ival++;
	cout << "----------------" << endl;
	cout << "ref1 = " << ref1 << endl;

	const int i = 512;
	const int &ref2 = i;
	cout << "----------------" << endl;
	cout << "ref2 = " << ref2 << endl;

	const int &ref3 = 256;
	cout << "----------------" << endl;
	cout << "ref3 = " << ref3 << endl;

	const int &ref4 = ival+1;
	cout << "----------------" << endl;
	cout << "ref4 = " << ref4 << endl;

	// err : ref++;

	return 0;
}
