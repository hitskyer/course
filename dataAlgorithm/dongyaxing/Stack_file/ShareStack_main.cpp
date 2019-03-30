#include <iostream>
#include "ShareStack.h"
#include "ShareStack.cpp"
using namespace std;

int main()
{
	ShareStack<int> ssk;
	//ssk.IsEmpty();
	//ssk.GetLeftStackTop();
	//ssk.GetRightStackTop();
	//ssk.GetLength();
	//ssk.LeftStackPop();
	//ssk.RightStackPop();
	int data1 = 10;
	int data2 = 20;
	ssk.LeftStackPush(data1);
	ssk.RightStackPush(data2);
	//ssk.PrintStack();
	//ssk.GetLeftStackTop();
	//ssk.GetRightStackTop();
	//ssk.GetLength();
	//ssk.LeftStackPop();
	//ssk.RightStackPop();
	for(int i = 0; i < 25; ++i)
	{
		ssk.LeftStackPush(data1);
		ssk.RightStackPush(data2);
	}
	ssk.PrintStack();


//	system("pause");
	return 0;
}
