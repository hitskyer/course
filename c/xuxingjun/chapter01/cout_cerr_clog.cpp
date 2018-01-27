#include <iostream>
using namespace std;

int main(void)
{
	// cout输出到标准输出流，>
	// clog输出到标准错误流，2>
	// clog与cout一样有缓冲区，但clog刷新优先级高于cout
	cout << "cout 1\n";
	clog << "clog 1\n";
	
	cout << "cout 2\n";
	clog << "clog 2\n";

	cout << "--------" << endl;

	// cout输出到标准输出流，>
	// cerr输出到标准错误流，2>
	// cerr没有缓冲区，会强制清空标准输出流缓冲区，并直接输出标准错误流
	cout << "cout 3\n";
	cerr << "cerr 1\n";
	
	cout << "cout 4\n";
	cerr << "cerr 2\n";

	cout << "--------" << endl;

	// 每次输出，都会强制清空缓冲区
	cout << "cout 5" << endl;
	clog << "clog 3" << endl;
	
	cout << "cout 6" << endl;
	clog << "clog 4" << endl;

	cout << "--------" << endl;

	// 每次输出，都会强制清空缓冲区
	cout << "cout 7" << endl;
	cerr << "cerr 3" << endl;
	
	cout << "cout 8" << endl;
	cerr << "cerr 4" << endl;
	return 0;
}
