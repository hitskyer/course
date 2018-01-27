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

	cout << "cout 5\n";
	clog << "clog 3\n";
	
	cout << "cout 6\n";
	clog << "clog 4\n";

	cout << "--------" << endl;

	cout << "cout 7\n";
	cerr << "cerr 3\n";
	
	cout << "cout 8\n";
	cerr << "cerr 4\n";
	return 0;
}
