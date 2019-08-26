#include <iostream>
#include "ACMatch.cpp"
using namespace std;

int main()
{
	AC ac;
	// 插入一些模式串
	ac.insert("hello");
	ac.insert("world");
	ac.insert("browse");
	ac.insert("snake");
	ac.insert("he");
	ac.insert("her");
	ac.insert("wor");
	ac.insert("br");
	// 建Trie树
	ac.buildFailurePointer();

	// 查找text中是否有模式串
	if (ac.find("hello"))
	{
		cout << "FIND IT" << endl;
	}
	else
	{
		cout << "NOT FIND IT" << endl;
	}
	// 查找text中是否有模式串
	if (ac.find("brother"))
	{
		cout << "FIND IT" << endl;
	}
	else
	{
		cout << "NOT FIND IT" << endl;
	}

	// 打印输出，且检查如果发现主串中含有模式串，则变为***
	ac.print("hellowoldh");
	ac.print("breosiof");
	ac.print("hisd");
	ac.print("her");
//	system("pause");
	return 0;
}
