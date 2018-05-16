#include <iostream>
using namespace std;


//理解:引用简单的来讲就是变量的别名，对引用的操作和对变量的操作完全一样 当对引用的值操作发生了变化，那么变量的值也会变化，他们实际上就是一样的。
//需要注意的是引用必须要初始化，不初始化的话编译的时候会报错。引用的话一定是指向一个变量，若是将一个常量给他会报错。
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
