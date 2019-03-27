#include<iostream>
#include"ArrStack.h"
using namespace std;
int main()
{
	AStack stk;
	stk.Empty();
	stk.GetLength();
	stk.GetTop();
	stk.Pop();
	stk.PrintStack();
	int n = 10;
	stk.Push(n);
	system("pause");
	return 0;
}