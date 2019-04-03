#include<iostream>
#include "Queue.h"
#include "Queue.cpp"
using namespace std;

int main()
{
	ListQueue<int> ql;
	for(int i = 0; i < 10; ++i)
	{
		if(0 == i || 3 == i || 6 == i || 9 == i)
		{
			ql.dequeue();
			cout << endl;
		}
		if(ql.empty())
			cout << "current queue is empty " << endl;
		ql.enqueue(i * 2 + 1);
		cout << " current queue length is " << ql.getlength() << endl;
		ql.print();
		cout << endl;
	}
	//system("pause");
	return 0;
}
