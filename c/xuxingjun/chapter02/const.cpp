#include <iostream>
using namespace std;
#include "ExampleForExtern.h"

//err : const bufSize;
const int bufSize = 512;
//const默认为文件内的局部变量
extern const int g_example_for_const;

void test1() {
	for (int i = 0; i < bufSize; ++i) ;
}
void test2() {
	for (int i = 0; i < bufSize; ++i) ;
}
int main() {
	// bufSize = 0; 
	cout << "bufSize = " << bufSize << endl;
	cout << g_example_for_const << endl;
	//cout << g_example_for_int << endl;            // 没有extern，默认是局部变量
	//cout << g_negative_example_for_const << endl; // 没有extern，默认是局部变量
	test1();
	test2();

	int a = 2;
	const int b = a;

	return 0;
}
