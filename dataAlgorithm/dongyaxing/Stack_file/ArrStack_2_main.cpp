#include "ArrStack_2.h"
#include "ArrStack_2.cpp"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	//*******1******未初始化栈的大小，采用默认大小20****
	//arrStack<int> ask1;
	//int n=-1 ,m=-1, k=-1;
	//n = ask1.GetCurrLength();
	//m = ask1.GetLength();
	//ask1.GetTop();
	//ask1.IsEmpty();
	//ask1.IsFull();
	//ask1.Pop();
	//int data1 = 10;
	//ask1.Push(data1);
	//k = ask1.GetLength();
	//n = ask1.GetCurrLength();
	//ask1.Print();
	//ask1.Clear();


	//*******2******未初始化栈的大小10****
	arrStack<int> ask2(10);
	int n=-1 ,m=-1, k=-1;
	n = ask2.GetCurrLength();
	m = ask2.GetLength();
	ask2.GetTop();
	ask2.IsEmpty();
	ask2.IsFull();
	ask2.Pop();
	int data2 = 10;
	ask2.Push(data2);
	for(int i = 1; i < 10; ++i)
	{
		k = 2 * i;
		ask2.Push(k);
	}
	ask2.Print();
	ask2.Push(k);
	m = ask2.GetLength();
	ask2.Print();
	//ask2.Clear();
	ask2.Pop();
	m = ask2.GetLength();
	ask2.Print();


	// ***********3****char********
	//arrStack<char> ask2(10);
	//int n=-1 ,m=-1;
	//n = ask2.GetCurrLength();
	//m = ask2.GetLength();
	//ask2.GetTop();
	//ask2.IsEmpty();
	//ask2.IsFull();
	//ask2.Pop();
	//char data2 = 'e';
	//ask2.Push(data2);
	//for(int i = 1; i < 10; ++i)
	//{
	//	ask2.Push(data2);
	//}
	//ask2.Print();
	//char data3 = 'f';
	//ask2.Push(data3);
	//m = ask2.GetLength();
	//ask2.Print();
	//ask2.Clear();
	//ask2.Pop();
	//m = ask2.GetLength();
	//ask2.Print();



	//system("pause");
	return 0;
}

