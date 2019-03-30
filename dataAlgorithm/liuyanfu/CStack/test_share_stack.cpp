#include <iostream>
#include "ShareStack.cpp"

using namespace std;
int main()
{
	UINT nCount = 10;
	UINT Toplimit = 0;
	while(Toplimit <= nCount)
	{
		ShareStack<int> istk;
		for(UINT i = 0; i < Toplimit; ++i)
		{
			if(i % 2 == 1)
				istk.LeftStackPush(20 + i * 2);
			else
				istk.RightStackPush(20 + i * 2);
		}

		istk.PrintStack();
		cout << "Current stack length is " << istk.GetLength() << endl;
		if(istk.GetLeftStackTop() == NULL)
			cout << "LeftStack is Empty" << endl;
		else
			cout << "The LeftStack Top data is " << *(istk.GetLeftStackTop()) << endl;
		if(istk.GetRightStackTop() == NULL)
			cout << "RightStack is Empty" << endl;
		else
			cout << "The RightStack Top data is " << *(istk.GetRightStackTop()) << endl;
		istk.LeftStackPop();
		istk.RigthStackPop();
		cout << "After pop stack, the rest of stack " << endl;
		istk.PrintStack();
		cout << endl;
		++Toplimit;
	}
	return 0;
}