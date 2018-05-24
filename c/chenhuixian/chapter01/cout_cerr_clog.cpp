#include <iostream>
using namespace std;

/*
 * 1. 课程范围："c++ primer"第4班第1.2.1节
 * 2. 课后练习：
 *    a) 描述"using namespace std;"给后继程序带来的变化
 *    b) g++ cout_cerr_clog.cpp -o out && ./out >& log.all && ./out > log.out 2> log.err
 *    c) 观察log.all，描述值得注意的现象，理解缓冲区、强制清空的概念；
 *    d) 观察log.out与log.err的区别，理解标准输出流、标准错误流；
 */
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
