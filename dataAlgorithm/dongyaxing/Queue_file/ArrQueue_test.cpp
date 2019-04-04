#include<iostream>
//#include"ArrQueue.h"
#include"ArrQueue.cpp"
using namespace std;

int main()
{
	ArrQueue<int> aq;
	// 空对测试
	if(!aq.DeQueue())
		std::cout << "dequeue failed" << std::endl;
	std::cout << std::endl;

	// 1个元素测试
	aq.EnQueue(20);
	std::cout << "queue length is: " << aq.GetLength() << std::endl;
	aq.Erase();
	if(aq.Empty())
		cout << "queue length is empty " << std::endl;
	std::cout << std::endl;

	// 多个元素测试
	for(int i = 0; i < 10; ++i)
	{
		aq.EnQueue(11+i);
	}
	std::cout << "queue length is: " << aq.GetLength() << std::endl;
	aq.Print();
	std::cout << std::endl;

	if(!aq.EnQueue(21))
	{
		std::cout << "enqueue is faile! queue is full! " << std::endl;
		std::cout << "queue length is:  " <<aq.GetLength() << std::endl;
	}
	std::cout << std::endl;

	std::cout <<"dequeue 2 elem: "<< std::endl;
	aq.DeQueue();
	aq.DeQueue();
	aq.Print();
	std::cout << "queue length is:  " <<aq.GetLength() << std::endl;
	std::cout << std::endl;

	std::cout <<"enqueue 2 elem: "<< std::endl;
	aq.EnQueue(22);
	aq.EnQueue(23);
	std::cout << "queue length is:  " <<aq.GetLength() << std::endl;
	aq.Print();
	//system("pause");

	ArrQueue<int> aq2(10);
	for(int i = 0; i < 10; ++i)
	{
		aq2.EnQueue(11+i);
	}
	std::cout << "queue length is: " << aq2.GetLength() << std::endl;
	aq2.Print();
	std::cout << std::endl;

	if(!aq2.EnQueue(21))
	{
		std::cout << "enqueue is faile! queue is full! " << std::endl;
		std::cout << "queue length is:  " <<aq2.GetLength() << std::endl;
	}
	std::cout << std::endl;

	std::cout <<"dequeue 2 elem: "<< std::endl;
	aq2.DeQueue();
	aq2.DeQueue();
	aq2.Print();
	std::cout << "queue length is:  " <<aq2.GetLength() << std::endl;
	std::cout << std::endl;

	std::cout <<"enqueue 2 elem: "<< std::endl;
	aq2.EnQueue(22);
	aq2.EnQueue(23);
	std::cout << "queue length is:  " <<aq2.GetLength() << std::endl;
	aq2.Print();

	return 0;
}
