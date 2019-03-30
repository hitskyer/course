#include <iostream>
#include "AStack.h"

using namespace std;
int main()
{
	UINT nCount = 5;
	UINT Toplimit = 0;
	while(Toplimit <= nCount)
	{
		AStack istk;
		for(UINT i = 0; i < Toplimit; ++i)
		{
			istk.Push(20 + i * 2);
		}

		istk.PrintStack();
		cout << "Current stack length is " << istk.GetLength() << endl;
		if(istk.GetTop() == NULL)
			cout << "Stack is Empty" << endl;
		else
			cout << "The stack Top data is " << *(istk.GetTop()) << endl;
		istk.Pop();
		cout << "After pop stack, the rest of stack " << endl;
		istk.PrintStack();
		cout << endl;
		++Toplimit;
	}
	return 0;
}