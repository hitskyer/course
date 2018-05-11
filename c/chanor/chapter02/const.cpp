#include <iostream>
using namespace std;

int intHdCnt = 30;
const int constHdCnt = 30;
extern const int extHdCnt = 30;

int main()
{
	int intCurCnt;
	cin >> intCurCnt;
	/**/
	intHdCnt++;
	if (intCurCnt < intHdCnt)
	{
		cout << "need to do sth.";
	}
	else
	{
		cout << "better.";
	}
	/*const:当前文件可用*,不可改/
	//constHdCnt++ :error	
	if (intCurCnt < constHdCnt)
	{
		cout << "need to do sth.";
	}
	else
	{
		cout << "better.";
	}

	/*extern const:多个文件中可用*/
	if (intCurCnt < extHdCnt)
	{
		cout << "need to do sth.";
	}
	else
	{
		cout << "better.";
	}
}
